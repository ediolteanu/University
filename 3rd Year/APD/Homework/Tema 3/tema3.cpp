#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define HORROR 1
#define COMEDY 2
#define FANTASY 3
#define SF 4
string horror("horror");
string comedy("comedy");
string fantasy("fantasy");
string sf("science-fiction");

static pthread_mutex_t mutex;
long cores;
static vector<string> order;

struct argument {
    long thread_id;
    string file_name;
}Arg;

struct arg_work {
    long thread_id;
    string file_name;
    int genre;
};

struct arg_proc {
    long thread_id;
    string file_name;
    int genre;
    int nr_cores;
};

static vector<char *> lines;
static uint current_line;

void *reader(void *arg) {
	struct argument argum = *(struct argument*) arg;
    string line, genre, paragraph;

    ifstream myfile;
    string file_name = argum.file_name;
    myfile.open(file_name);
    int count = 0;
    while (getline(myfile, line)) {
        //line.erase(line.size() - 1);
        if (line.compare(horror) == 0 || line.compare(comedy) == 0 ||
            line.compare(fantasy) == 0 || line.compare(sf) == 0) {
            genre = line;
            if (argum.thread_id == 0) {
                order.push_back(genre);
            }
        } else {
            if (line.empty()) {
                int size = paragraph.size() + 1;
                const char *str = paragraph.data();
                switch (argum.thread_id) {
                    case 0:
                        if (genre.compare(horror) == 0) {
                            //send 1
                            MPI_Send(&size, 1, MPI_INT, 1, count, MPI_COMM_WORLD);
                            MPI_Send(str, size, MPI_CHAR, 1, count, MPI_COMM_WORLD);
                            count++;
                        }
                        break;
                    case 1:
                        if (genre.compare(comedy) == 0) {
                            //send 2
                            MPI_Send(&size, 1, MPI_INT, 2, count, MPI_COMM_WORLD);
                            MPI_Send(str, size, MPI_CHAR, 2, count, MPI_COMM_WORLD);
                            count++;
                        }
                        break;
                    case 2:
                        if (genre.compare(fantasy) == 0) {
                            //send 3
                            MPI_Send(&size, 1, MPI_INT, 3, count, MPI_COMM_WORLD);
                            MPI_Send(str, size, MPI_CHAR, 3, count, MPI_COMM_WORLD);
                            count++;
                        }
                        break;
                    case 3:
                        if (genre.compare(sf) == 0) {
                            //send 4
                            MPI_Send(&size, 1, MPI_INT, 4, count, MPI_COMM_WORLD);
                            MPI_Send(str, size, MPI_CHAR, 4, count, MPI_COMM_WORLD);
                            count++;
                        }
                        break;
                    default:
                        break;
                }
                paragraph.clear();
            } else {
                paragraph += line + '\n';
            }
        }
        line.clear();
    }
    myfile.close();

    int size = -1;
    MPI_Send(&size, 1, MPI_INT, argum.thread_id + 1, count, MPI_COMM_WORLD);
    paragraph.clear();
    

	pthread_exit(NULL);
}

void *process_horror(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        int start = current_line;
        current_line += min(20, (int) lines.size() - start);
        int end = current_line;
        pthread_mutex_unlock(&mutex);

        for (int i = start; i < end; i++) { /// eroare
            pthread_mutex_lock(&mutex);
            char *line = lines.at(i);
            pthread_mutex_unlock(&mutex);
            char *new_line = (char *) calloc(strlen(line) * 2, sizeof(char));
            int k = 0;
            for (uint j = 0; j < strlen(line); j++) {
                new_line[k++] = line[j];
                if ((line[j] >= 65 && line[j] <= 90) || 
                    (line[j] >= 97 && line[j] <= 122)) {
                    if (line[j] != 65 && line[j] != 69 && line[j] != 73 && 
                        line[j] != 79 && line[j] != 85 && line[j] != 97 &&
                        line[j] != 101 && line[j] != 105 && line[j] != 111 &&
                        line[j] != 117) {
                        new_line[k++] = tolower(line[j]);
                    }
                }
            }
            pthread_mutex_lock(&mutex);
            lines.erase(lines.begin() + i);
            lines.insert(lines.begin() + i, new_line);
            pthread_mutex_unlock(&mutex);
        }
        if (current_line == lines.size()) break;
    }
    pthread_exit(NULL);
}

void *process_comedy(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        int start = current_line;
        current_line += min(20, (int) lines.size() - start);
        int end = current_line;
        pthread_mutex_unlock(&mutex);
        int count;
        for (int i = start; i < end; i++) {
            pthread_mutex_lock(&mutex);
            char *line = lines.at(i);
            pthread_mutex_unlock(&mutex);
            count = 0;
            for(uint j = 0; j < strlen(line); j++) {
                if (line[j] == ' ') {
                    count = 0;
                } else {
                    if (count % 2 == 1) {
                        line[j] = toupper(line[j]);
                    }
                    count++;
                }
            }
        }
        if (current_line == lines.size()) break;
    }
    pthread_exit(NULL);
}

void *process_fantasy(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        int start = current_line;
        current_line += min(20, (int) lines.size() - start);
        int end = current_line;
        pthread_mutex_unlock(&mutex);
        int count;
        for (int i = start; i < end; i++) {
            pthread_mutex_lock(&mutex);
            char *line = lines.at(i);
            pthread_mutex_unlock(&mutex);
            count = 0;
            for(uint j = 0; j < strlen(line); j++) {
                if (line[j] == ' ') {
                    count = 0;
                } else {
                    if (count == 0) {
                        line[j] = toupper(line[j]);
                    }
                    count++;
                }
            }
        }
        if (current_line == lines.size()) break;
    }
    pthread_exit(NULL);
}

void *process_sf(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        int start = current_line;
        current_line += min(20, (int) lines.size() - start);
        int end = current_line;
        pthread_mutex_unlock(&mutex);
        int count;
        for (int i = start; i < end; i++) {
            pthread_mutex_lock(&mutex);
            char *line = lines.at(i);
            pthread_mutex_unlock(&mutex);
            count = 0;
            int i1 = 0;
            int i2 = 0;
            for(uint j = 0; j < strlen(line) + 1; j++) {
                if (line[j] == ' ' || line[j] == '\t' || line[j] == '\n' || 
                    line[j] == '\0' || line[j] == '\r') {
                    i1 = i2;
                    i2 = j;
                    count++;
                }
                if (count == 7) {
                    char c;
                    int l = 0;
                    for (int k = i1 + 1; k < i2; k++) {
                        c = line[k];
                        line[k] = line[i2 - l - 1];
                        line[i2 - l - 1] = c; 
                        l++;
                        if (k >= i2 - l - 1) break;
                    }
                    count = 0;
                }

            }
            
        }
        if (current_line == lines.size()) break;
    }
    pthread_exit(NULL);
}

void *start_worker(void *arg) {
    struct arg_work argw = *(struct arg_work *) arg;
    vector<string> paragraphs;
    int size;
    MPI_Status status;
    int count = 0;
    while(1) {
        MPI_Recv(&size, 1, MPI_INT, 0, count, MPI_COMM_WORLD, &status);
        if (size == -1) {
            break;
        }
        char *paragraph = (char *) malloc(sizeof(char) * size);
        MPI_Recv(paragraph, size, MPI_CHAR, 0, count, MPI_COMM_WORLD, &status);
        count++;

        struct arg_proc argl; 
        char *tok;
        tok = strtok(paragraph, "\n");
        while (tok != NULL) {
            lines.push_back(tok);
            tok = strtok(NULL, "\n");
        }
        long procs = ceil((double) lines.size() / 20);

        int nr_th = min(procs , cores - 1);

        pthread_t tid[nr_th];
        current_line = 0;
        pthread_mutex_init(&mutex, NULL);
        for (int i = 0; i < nr_th; i++) {
            argl.thread_id = i;
            argl.file_name = argw.file_name;
            argl.genre = argw.genre;
            argl.nr_cores = nr_th;
            
            switch(argw.genre) {
                case 1:
                    pthread_create(&tid[i], NULL, process_horror, &argl);
                    break; 
                case 2:
                    pthread_create(&tid[i], NULL, process_comedy, &argl);
                    break;
                case 3: 
                    pthread_create(&tid[i], NULL, process_fantasy, &argl);
                    break;
                case 4:
                    pthread_create(&tid[i], NULL, process_sf, &argl);
                    break;
            }
        }
        for (int i = 0; i < nr_th; i++) {
            pthread_join(tid[i], NULL);
        }
        pthread_mutex_destroy(&mutex);
        string parag;
        for (uint i = 0; i < lines.size(); i++) {
            parag.append(lines.at(i));
            parag.append("\n");
        }
        lines.clear();
        paragraphs.push_back(parag);
        
    }
    
    const char *paragraph;
    for (uint i = 0; i < paragraphs.size(); i++) {
        size = paragraphs.at(i).size() + 1;
        paragraph = paragraphs.at(i).data();
        MPI_Send(&size, 1, MPI_INT, 0, i, MPI_COMM_WORLD);
        MPI_Send(paragraph, size, MPI_CHAR, 0, i, MPI_COMM_WORLD);
    }
    paragraphs.clear();

    pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
    int numtasks, rank;
    int provided;
    cores = sysconf(_SC_NPROCESSORS_CONF);

    MPI_Init_thread(&argc, &argv, MPI_THREAD_MULTIPLE, &provided);
    
    MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) { //Master
        struct argument arg[4];
      
    	pthread_t tid[4];

    	for (int i = 0; i < 4; i++) {
            arg[i].thread_id = i;
            arg[i].file_name = argv[1];
			pthread_create(&tid[i], NULL, reader, &arg[i]);
		}

		for (int i = 0; i < 4; i++) {
			pthread_join(tid[i], NULL);
		}
        int size;
        MPI_Status status;
        vector<string> v;
        int hc = 0, cc = 0, fc = 0, sfc = 0;
        for (uint i = 0 ; i < order.size(); i++) {
            if (order.at(i).compare(horror) == 0) {
                MPI_Recv(&size, 1, MPI_INT, 1, hc, MPI_COMM_WORLD, &status);
                char *paragraph = (char *) malloc(sizeof(char) * size);
                MPI_Recv(paragraph, size, MPI_CHAR, 1, hc, MPI_COMM_WORLD, &status);
                hc++;
                v.push_back(paragraph);
            }
            if (order.at(i).compare(comedy) == 0) {
                MPI_Recv(&size, 1, MPI_INT, 2, cc, MPI_COMM_WORLD, &status);
                char *paragraph = (char *) malloc(sizeof(char) * size);
                MPI_Recv(paragraph, size, MPI_CHAR, 2, cc, MPI_COMM_WORLD, &status);
                cc++;
                v.push_back(paragraph);
            }
            if (order.at(i).compare(fantasy) == 0) {
                MPI_Recv(&size, 1, MPI_INT, 3, fc, MPI_COMM_WORLD, &status);
                char *paragraph = (char *) malloc(sizeof(char) * size);
                MPI_Recv(paragraph, size, MPI_CHAR, 3, fc, MPI_COMM_WORLD, &status);
                fc++;
                v.push_back(paragraph);
            }
            if (order.at(i).compare(sf) == 0) {
                MPI_Recv(&size, 1, MPI_INT, 4, sfc, MPI_COMM_WORLD, &status);
                char *paragraph = (char *) malloc(sizeof(char) * size);
                MPI_Recv(paragraph, size, MPI_CHAR, 4, sfc, MPI_COMM_WORLD, &status);
                sfc++;
                v.push_back(paragraph);
            }
        }

        ofstream outfile;
        string file_name = argv[1];
        file_name[file_name.size() - 2] = 'u';
        file_name[file_name.size() - 3] = 'o';
        outfile.open(file_name);
        for (uint i = 0; i < v.size(); i++) {
            outfile << order.at(i) << endl;
            if (i == v.size() - 1) {
                outfile << v.at(i);
            }
            else {
                outfile << v.at(i) << endl;
            }
        }
        v.clear();

    } else if (rank == 1) { //horror
        struct arg_work arg;
        arg.thread_id = 0;
        arg.file_name = argv[1];
        arg.genre = HORROR;
        pthread_t tid;
        pthread_create(&tid, NULL, start_worker, &arg);
        
        pthread_join(tid, NULL);
    } else if (rank == 2) { //comedy
        struct arg_work arg;
        arg.thread_id = 0;
        arg.file_name = argv[1];
        arg.genre = COMEDY;
        pthread_t tid;
        pthread_create(&tid, NULL, start_worker, &arg);
        
        pthread_join(tid, NULL);
    } else if (rank == 3) { //fantasy
        struct arg_work arg;
        arg.thread_id = 0;
        arg.file_name = argv[1];
        arg.genre = FANTASY;
        pthread_t tid;
        pthread_create(&tid, NULL, start_worker, &arg);
        
        pthread_join(tid, NULL);
    } else { //science-fiction
        struct arg_work arg;
        arg.thread_id = 0;
        arg.file_name = argv[1];
        arg.genre = SF;
        pthread_t tid;
        pthread_create(&tid, NULL, start_worker, &arg);
        
        pthread_join(tid, NULL);
    }

    MPI_Finalize();
    return 0;

}