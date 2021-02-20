#include "skel.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <netinet/if_ether.h>

#define size 64284
#define IP_OFF (sizeof(struct ether_header))
#define ICMP_OFF (IP_OFF + sizeof(struct iphdr))

struct route_table_entry {
	uint32_t prefix;
	uint32_t next_hop;
	uint32_t mask;
	int interface;
} RTABLE;

struct arp_entry {
  uint32_t ip;
  uint8_t mac[6];
} arp;

struct route_table_entry *rtable;
int rtable_len;
struct arp_entry *arp_table;
int arp_table_len = 0;

void merge(struct route_table_entry *v, int i, int m, int j) {
  int a = i, b = m + 1;
  struct route_table_entry *u = (struct route_table_entry *) malloc((j - i + 1)
                                    * sizeof(struct route_table_entry));
  int c = 0;
  while (a <= m && b <= j) {
    if (v[a].prefix <= v[b].prefix) {
      if (v[a].prefix == v[b].prefix) {
        if (v[a].mask <= v[b].mask) {
          u[c++] = v[a++];
        } else {
          u[c++] = v[b++];
        }
      } else {
        u[c++] = v[a++];
      }
    }
    else u[c++] = v[b++];
  }
  
  while (a <= m)
    u[c++] = v[a++];
  
  while (b <= j)
    u[c++] = v[b++];
    
  for (int l = i, k = 0; l <= j; l++)
    v[l] = u[k++];
  
  free(u);
}

void merge_sort(struct route_table_entry *v, int i, int j) {
  if (i < j) {
    int m = (i + j) / 2;
    merge_sort(v, i, m);
    merge_sort(v, m + 1, j);
    merge(v, i, m, j);
  }
}

struct route_table_entry *parse_rtable(char *filename) {
  FILE *f = fopen(filename, "r");
  char pref[20];
  char nexth[20];
  char mask[20];
  int interf;
  
  rtable = malloc(size * sizeof(struct route_table_entry));
                  
  int i = 0;
  int rs = fscanf(f, "%s %s %s %d\n", pref, nexth, mask, &interf);
  while (rs > 0) {
    rtable[i].prefix = inet_addr(pref);
    rtable[i].next_hop = inet_addr(nexth);
    rtable[i].mask = inet_addr(mask);
    rtable[i].interface = interf;
    rs = fscanf(f, "%s %s %s %d", pref, nexth, mask, &interf);
    i++; 
  }
  
  rtable_len = i - 1;
  merge_sort(rtable, 0, rtable_len);
  
  return rtable;
}

struct route_table_entry *get_best_route(int i , int j, __u32 x) {
  if (i <= j) {
    int m = (i + j) / 2;
    if (rtable[m].prefix == (rtable[m].mask & x)) {
      if ((m == j) || ((m != j) && 
                (rtable[m + 1].prefix != (rtable[m + 1].mask & x))))
        return &rtable[m];
    } 
    if (rtable[m].prefix > (rtable[m].mask & x))
      return get_best_route(i, m - 1, x);
    if ((rtable[m].prefix < (rtable[m].mask & x)) || 
        ((rtable[m].prefix == (rtable[m].mask & x)) &&
         (rtable[m + 1].prefix == (rtable[m + 1].mask & x))))
      return get_best_route(m + 1, j, x);
  }
  
  return NULL;
}


uint16_t checksum(void* vdata, size_t length) {
	// Cast the data pointer to one that can be indexed.
	char* data=(char*)vdata;

	// Initialise the accumulator.
	uint64_t acc=0xffff;

	// Handle any partial block at the start of the data.
	unsigned int offset=((uintptr_t)data)&3;
	if (offset) {
		size_t count=4-offset;
		if (count>length) count=length;
		uint32_t word=0;
		memcpy(offset+(char*)&word,data,count);
		acc+=ntohl(word);
		data+=count;
		length-=count;
	}

	// Handle any complete 32-bit blocks.
	char* data_end=data+(length&~3);
	while (data!=data_end) {
		uint32_t word;
		memcpy(&word,data,4);
		acc+=ntohl(word);
		data+=4;
	}
	length&=3;

	// Handle any partial block at the end of the data.
	if (length) {
		uint32_t word=0;
		memcpy(&word,data,length);
		acc+=ntohl(word);
	}

	// Handle deferred carries.
	acc=(acc&0xffffffff)+(acc>>32);
	while (acc>>16) {
		acc=(acc&0xffff)+(acc>>16);
	}

	// If the data began at an odd byte address
	// then reverse the byte order to compensate.
	if (offset&1) {
		acc=((acc&0xff00)>>8)|((acc&0x00ff)<<8);
	}

	// Return the checksum in network byte order.
	return htons(~acc);
}

struct arp_entry *get_arp_entry(uint32_t ip) {
  int index = -10;
	for (int i = 0; i < arp_table_len; i++) {
	  if (arp_table[i].ip == ip) {
      index = i;
	  }
	}
	if (index == -10)
	  return NULL;
  else return &arp_table[index];
}

int main(int argc, char *argv[])
{
  setvbuf(stdout, NULL, _IONBF, 0);
	packet m;
	int rc;

	init();
  char *filename = "rtable.txt";
  rtable = parse_rtable(filename);
  arp_table = malloc(sizeof(struct arp_entry) * 4);
  queue q = queue_create();
	while (1) {
		rc = get_packet(&m);
		DIE(rc < 0, "get_message");

	  struct ether_header *eth_hdr = (struct ether_header *) m.payload;
	  
	  if (eth_hdr->ether_type == htons(ETHERTYPE_IP)) {
	    struct iphdr *ip_hdr = (struct iphdr *) (m.payload + IP_OFF);
	    if (checksum(ip_hdr, sizeof(struct iphdr)) != 0) {
	      continue;
	    }
	    if (inet_addr(get_interface_ip(m.interface)) == ip_hdr->daddr) {
	      struct icmphdr *icmp_hdr = (struct icmphdr *)(m.payload + ICMP_OFF);
	      if (icmp_hdr->type == ICMP_ECHO) {
	        icmp_hdr->type = ICMP_ECHOREPLY;
	      }
	      icmp_hdr->checksum = 0;
	      icmp_hdr->checksum = checksum(icmp_hdr, sizeof(struct icmphdr));
	      ip_hdr->version = 4;
	      uint32_t aux = inet_addr(get_interface_ip(m.interface));
	      ip_hdr->daddr = ip_hdr->saddr;
	      ip_hdr->saddr = aux;
	      ip_hdr->ttl -= 1;
	      ip_hdr->check = 0;
        ip_hdr->check = checksum(ip_hdr, sizeof(struct iphdr));
	      memcpy(eth_hdr->ether_dhost, eth_hdr->ether_shost, 6 * sizeof(u_char));
	      get_interface_mac(m.interface, eth_hdr->ether_shost);
	      eth_hdr->ether_type = htons(ETHERTYPE_IP);
	      send_packet(m.interface, &m);
	      continue;
	    } else {
	      if (ip_hdr->ttl <= 1) {
	        struct icmphdr *icmp_hdr = (struct icmphdr *)(m.payload + ICMP_OFF);
	        memcpy(m.payload + ICMP_OFF + sizeof(struct icmphdr), ip_hdr, 
	                        sizeof(struct iphdr) + 64);
	        m.len = sizeof(ICMP_OFF) + sizeof(struct icmphdr) + 
	                  sizeof(struct iphdr) + 64;
	        icmp_hdr->code = ICMP_EXC_TTL;
	        icmp_hdr->type = ICMP_TIME_EXCEEDED;
	        icmp_hdr->checksum = 0;
	        icmp_hdr->checksum = checksum(icmp_hdr, m.len - sizeof(ICMP_OFF));
	        ip_hdr->version = 4;
	        uint32_t aux = ip_hdr->saddr;
	        ip_hdr->saddr = ip_hdr->daddr;
	        ip_hdr->daddr = aux;
	        ip_hdr->ttl = 64;
	        ip_hdr->id = 2 * ip_hdr->id;
	        ip_hdr->frag_off = 0;
	        ip_hdr->protocol = 1;
	        ip_hdr->check = 0;
	        ip_hdr->tot_len = htons(ntohs(ip_hdr->tot_len) + sizeof(struct iphdr)
	                                          + sizeof(struct icmphdr));
          ip_hdr->check = checksum(ip_hdr, sizeof(struct iphdr));
	        memcpy(eth_hdr->ether_dhost, eth_hdr->ether_shost, 6 * sizeof(u_char));
	        get_interface_mac(m.interface, eth_hdr->ether_shost);
	        eth_hdr->ether_type = htons(ETHERTYPE_IP);
	        send_packet(m.interface, &m);
	        continue;   
	      }
	      struct route_table_entry *r_entry = get_best_route(0, rtable_len, 
	                                                          ip_hdr->daddr);
	      if (r_entry == NULL) {
	        struct icmphdr *icmp_hdr = (struct icmphdr *)(m.payload + ICMP_OFF);
	        memcpy(m.payload + ICMP_OFF + sizeof(struct icmphdr), ip_hdr, 
	                        sizeof(struct iphdr) + 64);
	        m.len = sizeof(ICMP_OFF) + sizeof(struct icmphdr) + 
	                  sizeof(struct iphdr) + 64;
	        icmp_hdr->code = 0;
	        icmp_hdr->type = ICMP_DEST_UNREACH;
	        icmp_hdr->checksum = 0;
	        icmp_hdr->checksum = checksum(icmp_hdr, m.len - sizeof(ICMP_OFF));
	        ip_hdr->version = 4;
	        uint32_t aux = ip_hdr->saddr;
	        ip_hdr->saddr = ip_hdr->daddr;
	        ip_hdr->daddr = aux;
	        ip_hdr->ttl = 64;
	        ip_hdr->id = 2 * ip_hdr->id;
	        ip_hdr->frag_off = 0;
	        ip_hdr->protocol = 1;
	        ip_hdr->check = 0;
	        ip_hdr->tot_len = htons(ntohs(ip_hdr->tot_len) + sizeof(struct iphdr)
	                                          + sizeof(struct icmphdr));
          ip_hdr->check = checksum(ip_hdr, sizeof(struct iphdr));
	        memcpy(eth_hdr->ether_dhost, eth_hdr->ether_shost, 6 * sizeof(u_char));
	        get_interface_mac(m.interface, eth_hdr->ether_shost);
	        eth_hdr->ether_type = htons(ETHERTYPE_IP);
	        send_packet(m.interface, &m);
	        continue;
	      } else {
	        ip_hdr->ttl -= 1;
	        ip_hdr->check = 0;
          ip_hdr->check = checksum(ip_hdr, sizeof(struct iphdr));
	        
	        struct arp_entry *arp_ent = get_arp_entry(r_entry->next_hop);
	        if (arp_ent != NULL) {
	          get_interface_mac(r_entry->interface, eth_hdr->ether_shost);
	          memcpy(eth_hdr->ether_dhost, arp_ent->mac, 6);
	          send_packet(r_entry->interface, &m);
	          continue;
	        } else {
	            //salveaza pachetul si pune-l in coada
	            packet *aux = (packet *) malloc(sizeof(packet));
	            memcpy(aux, &m, sizeof(packet));
	            queue_enq(q, aux);
	            //send request
	            packet arp_req;
	            struct ether_header *r_eth_hdr = 
	                (struct ether_header *) malloc(sizeof(struct ether_header));
	            hwaddr_aton("ff:ff:ff:ff:ff:ff",r_eth_hdr->ether_dhost);
	            get_interface_mac(r_entry->interface, r_eth_hdr->ether_shost);
	            r_eth_hdr->ether_type = htons(ETHERTYPE_ARP);
	            struct ether_arp *eth_arp = 
	                (struct ether_arp *) malloc(sizeof(struct ether_arp));
	            eth_arp->ea_hdr.ar_hrd = htons(ARPHRD_ETHER);
	            eth_arp->ea_hdr.ar_pro = htons(0x0800);
	            eth_arp->ea_hdr.ar_hln = 6;
	            eth_arp->ea_hdr.ar_pln = 4;
	            eth_arp->ea_hdr.ar_op = htons(ARPOP_REQUEST);
	            
	            struct in_addr inadr;
	            inet_aton(get_interface_ip(r_entry->interface), &inadr);
	            u_char *bytes = (u_char *) malloc(4 * sizeof(u_char));
	            uint32_t n = inadr.s_addr;
	            bytes[3] = (n >> 24) & 0xFF;
	            bytes[2] = (n >> 16) & 0xFF;
	            bytes[1] = (n >> 8) & 0xFF;
	            bytes[0] = n & 0xFF;
	            memcpy(eth_arp->arp_spa, bytes, 4);
	            get_interface_mac(r_entry->interface, eth_arp->arp_sha);
	            
	            n = ip_hdr->daddr;
	            bytes[3] = (n >> 24) & 0xFF;
	            bytes[2] = (n >> 16) & 0xFF;
	            bytes[1] = (n >> 8) & 0xFF;
	            bytes[0] = n & 0xFF;
	            memcpy(eth_arp->arp_tpa, bytes, 4);
              hwaddr_aton("ff:ff:ff:ff:ff:ff", eth_arp->arp_tha);
	            memcpy(arp_req.payload, r_eth_hdr, sizeof(struct ether_header));
	            memcpy(arp_req.payload + sizeof(struct ether_header), eth_arp, 
	                        sizeof(struct ether_arp));
	            arp_req.len = sizeof(struct ether_header) + 
	                  sizeof(struct ether_arp);
	            arp_req.interface = r_entry->interface;
	            send_packet(r_entry->interface, &arp_req);
	            continue;
	        }
	      }
	    }
	  } else if (eth_hdr->ether_type == htons(ETHERTYPE_ARP)) {
	      struct ether_arp *eth_arp = (struct ether_arp *) (m.payload +
	                          sizeof(struct ether_header));
	      if (eth_arp->ea_hdr.ar_op == htons(ARPOP_REQUEST)) { //got request
	        struct in_addr inadr;
	        inet_aton(get_interface_ip(m.interface), &inadr);
	        u_char *bytes = (u_char *) malloc(4 * sizeof(u_char));
	        uint32_t n = inadr.s_addr;
	        bytes[3] = (n >> 24) & 0xFF;
	        bytes[2] = (n >> 16) & 0xFF;
	        bytes[1] = (n >> 8) & 0xFF;
	        bytes[0] = n & 0xFF;
	        uint32_t aux_ip = 0;
	        aux_ip = aux_ip + eth_arp->arp_tpa[3];
	        aux_ip = aux_ip << 8;
	        aux_ip = aux_ip + eth_arp->arp_tpa[2];
	        aux_ip = aux_ip << 8;
	        aux_ip = aux_ip + eth_arp->arp_tpa[1];
	        aux_ip = aux_ip << 8;
	        aux_ip = aux_ip + eth_arp->arp_tpa[0];
	        if (aux_ip != inadr.s_addr) {
	          continue;
	        }
	        //send reply
	        memcpy(eth_hdr->ether_dhost, eth_hdr->ether_shost, 
	                  6 * sizeof(u_char));
	        get_interface_mac(m.interface, eth_hdr->ether_shost);

	        eth_arp->ea_hdr.ar_op = htons(ARPOP_REPLY);
	        memcpy(eth_arp->arp_tpa, eth_arp->arp_spa, 4);
	        memcpy(eth_arp->arp_tha, eth_arp->arp_sha, 6);
	        memcpy(eth_arp->arp_spa, bytes, 4 * (sizeof(u_char)));
	        get_interface_mac(m.interface, eth_arp->arp_sha);
	        
	        send_packet(m.interface, &m);
	        continue;
	        
	      } else if (eth_arp->ea_hdr.ar_op == htons(ARPOP_REPLY)) { //got reply
	        //process reply
	        printf("sendreply\n");
	        struct ether_arp *eth_arp = (struct ether_arp *) (m.payload +
	                          sizeof(struct ether_header));
	        uint32_t aux_ip = 0;
	        aux_ip = aux_ip + eth_arp->arp_spa[3];
	        aux_ip = aux_ip << 8;
	        aux_ip = aux_ip + eth_arp->arp_spa[2];
	        aux_ip = aux_ip << 8;
	        aux_ip = aux_ip + eth_arp->arp_spa[1];
	        aux_ip = aux_ip << 8;
	        aux_ip = aux_ip + eth_arp->arp_spa[0];
	        for (int i = 0; i < arp_table_len; i++) {
	          if (arp_table[i].ip == aux_ip) continue;
	        }
	        memcpy(&arp_table[arp_table_len].ip, &aux_ip, 4);
	        memcpy(&arp_table[arp_table_len].mac, eth_arp->arp_sha, 6);
	        arp_table_len = arp_table_len + 1;
	        queue aux_q = queue_create();
	        packet *temp;
	        while(!queue_empty(q)) {
	          temp = queue_deq(q);
	          struct ether_header *eth_hdr = (struct ether_header *) temp->payload;
	          struct iphdr *ip_hdr = (struct iphdr *) (temp->payload + IP_OFF);
	          struct route_table_entry *r_entry = get_best_route(0, rtable_len, 
	                                                          ip_hdr->daddr);
	          struct arp_entry *arp_ent = get_arp_entry(r_entry->next_hop);
	          if (arp_ent != NULL) {
	            get_interface_mac(r_entry->interface, eth_hdr->ether_shost);
	            memcpy(eth_hdr->ether_dhost, arp_ent->mac, 6);
	            printf("sendp");
	            send_packet(r_entry->interface, temp);
	            continue;
	          } else {
	            printf("no_arp_ent\n");
	            queue_enq(aux_q, temp);
	          }
	        }
	        while(!queue_empty(aux_q)) {
	          temp = queue_deq(aux_q);
	          queue_enq(q, temp);
	        }
	        
	      }
	  }
	                         
	  
	}
	return 0;
}
