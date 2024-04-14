#include "csapp.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);

void rio_readinitb(rio_t *rp, int fd);

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);

int main(int argc, char **argv) {
    int n; 
    rio_t rio;
    char buf[MAXLINE];

    rio_readinitb(&rio, STDIN_FILENO);
    while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        rio_writen(STDOUT_FILENO, buf, n);
    }
    return 0;
}