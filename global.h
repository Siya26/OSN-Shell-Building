#include "header.h"
#ifndef GLOBAL
#define GLOBAL
#define no 10000

char *h;
char *u;
char *e;
char *m;
char **ne;

char *d;
char *p;
char *b;
char *c;
char *path;
char *mum;

char *str;
char **n;
char **a;
char *q[no];
char ht[21][no];
char *x;
char *arr[no];

struct stat a1;
char *ds;
char *nik;
char har[no][no];
char *jas;
char *pg;

struct cess 
{
    char name[no];
    int index;
    int nb;
    int status;
};
struct cess c1[no];

void echo();
void pwd();
void cdf(int *count, int *cd);
void his(int *k);
void print(int *k);

int ls(int flag_ls);
void ls1(int *y);
int ls_l(int *zz);
int ls_al(int *zz);
int lsn(int *zz);
int ls_a(int *zz);

int pin();
int dis();
int disn(char dv[], char pav[]);
int dis_ff(char dv[], char pav[], int vib);
int dis_fd(char dv[], char pav[]);
int dis_d(char dv[], char pav[]);
int dis_f(char dv[], char pav[]);

void kes(int *so);
int fbg(int kom, int *so, int *count, int *cd, int *pro);
int jobs();
void bub(int nonames);
int sig();
int fg();
int bg();

int io();
int pip();
void ctrl_c();
void ctrl_z();

extern int pro_pid;

#endif