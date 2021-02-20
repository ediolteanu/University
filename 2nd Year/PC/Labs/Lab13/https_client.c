#include <openssl/ssl.h>
#include <openssl/bio.h>
#include <openssl/err.h>

#include "stdio.h"
#include "string.h"

int main()
{
    BIO * bio;
    SSL * ssl;
    SSL_CTX * ctx;

    int p;

    char * request = "GET / HTTP/1.0\r\nHost: www.verisign.com\r\n\r\n";
    char r[1024];
    /* initializare librarie */

    SSL_library_init ();
    ERR_load_BIO_strings();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();

    /* TO DO initializare context */

    ctx = SSL_CTX_new(SSLv23_client_method());

    /* incarca trust store */


    if(! SSL_CTX_load_verify_locations(ctx, "TrustStore.pem", NULL))
    {
        fprintf(stderr, "Error loading trust store\n");
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return 0;
    }


    /* stabileste conexiune */

    bio = BIO_new_ssl_connect(ctx);
   
    /* Seteaza flag SSL_MODE_AUTO_RETRY  */

    BIO_get_ssl(bio, & ssl);
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);

    /* TO DO setup conexiune */
    BIO_set_conn_hostname(bio, "verisign.com:443");
    if(BIO_do_connect(bio) <= 0) {

        fprintf(stderr, "Error connecting\n");
        ERR_print_errors_fp(stderr);
        BIO_free_all(bio);
    }

    /* TO DO verifica certificat */
    if(SSL_get_verify_result(ssl) != X509_V_OK)
    {
        fprintf(stderr, "Error certificate\n");
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        BIO_free_all(bio);
    }


    /* Trimite request */

    BIO_write(bio, request, strlen(request));

    /* TO DO Citeste raspuns si pregateste  output*/
    FILE *f = fopen("output.html", "w");
    int x = BIO_read(bio, r, 1024);
    
    do {
        x = BIO_read(bio, r, 1024);
        if(x == 0)
        {
            /* trateaza conexiune inchisa*/
            fprintf(stderr, "Connection closed\n");
            ERR_print_errors_fp(stderr);
        }
        else if (x < 0)
        {
            if (! BIO_should_retry(bio))
            {
                /* trateaza esec operatie read */
                fprintf(stderr, "Error reading\n");
                ERR_print_errors_fp(stderr);
            }

        } 
        fwrite(r, 1, x, f);
        memset(r, 0, sizeof(r));
    } while(x > 0);

    fclose(f);
    /* Inchide conexiune si elibereaza context */

    BIO_free_all(bio);
    SSL_CTX_free(ctx);
    return 0;
}
