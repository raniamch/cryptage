#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Values {
    int FN;
    int q;  //q and p - can be only divided by itself and one, for KeyN
    int p;
    int k;
};
struct Keys {
    int KeyN;
    int KeyE;
    int KeyD;
};
struct Formula {
    int m1[30];
    int c1[30];
    int m[30];
    int c[30];
};
int CreatingExponent(struct Keys *a, struct Values *b);


// Video resolution
#define W 720
#define H 720
 
// Allocate a buffer to store one frame
unsigned char frame0[H][W][3] = {0};
unsigned char frame[H][W][3] = {0};
unsigned char frame1[H][W][3] = {0};
unsigned char framex[H][W][3] = {0};
unsigned char frames[H][W][3] = {0};






int main() {



int x, y, count,count1,count2;
     FILE *pipein;
    // Open an input pipe from ffmpeg and an output pipe to a second instance of ffmpeg
    FILE *pipein0 = popen("ffmpeg -i video1.mp4 -f image2pipe -vcodec rawvideo -pix_fmt rgb24 -", "r");
    
    FILE *pipeout = popen("ffmpeg -y -f rawvideo -vcodec rawvideo -pix_fmt rgb24 -s 1280x720 -r 25 -i - -f mp4 -q:v 5 -an -vcodec mpeg4 resultatv1.mp4", "w");



 // Write first 50 frames using original video title image from title_original.png
   pipein = popen("ffmpeg -i 2.png -f image2pipe -vcodec rawvideo -pix_fmt rgb24 -", "r");





    char k[255],l[255];
    int i=2,j=2;
    struct Formula *prt2=NULL;
    struct Values *prt1=NULL;
    struct Keys *prt=NULL;
    prt = (struct Keys*) malloc(sizeof(struct Keys));
    prt1 = (struct Values*) malloc(sizeof(struct Values));
    prt2 = (struct Formula*) malloc(sizeof(struct Formula));
    printf("add prime number for q \n");
    scanf("%d",&prt1->q);
    while(i<=prt1->q){
        if(prt1->q%i!=0){
            i++; }
        else{
            if(i==prt1->q){
                printf("prime \n");
                break;
            }
            else{
                printf("it is not prime \n");
                printf("Please try again \n");
                return main();
            }}}
    printf("add prime number for p \n");
    scanf("%d",&prt1->p);
    while(j<=prt1->p){
    if(prt1->p%j!=0){
      j++; }
    else{
        if(j==prt1->p){
            printf("prime \n");
            break;
        }
         else{
            printf("it is not prime \n");
            printf("Please try again \n");
            return main();
        }}}

    prt->KeyN=prt1->p * prt1->q;
    printf("Number of First Public Key n = %d\n", prt->KeyN);
    prt1->FN=(prt1->p-1)*(prt1->q-1);
    printf("Number Phi for n value = %d\n", prt1->FN);

    CreatingExponent(prt,prt1);

    int q[30];
   
   
    

    if((prt->KeyN*prt->KeyD)%prt1->FN==1){
     printf("Not a Secret Key, Try again %d\n", prt->KeyD);
     return main();
    }
    else {
        printf("Number of Secret Key d = %d \n", prt->KeyD);
    }

while(1){



// Read a frame from the input pipe into the buffer
        count = fread(frame0, 1, H*W*3, pipein0);
        count1 = fread(framex, 1, H*W*3, pipein);
        // If we didn't get a frame of video, we're probably at the end
        if (count != H*W*3) break;
         
        // Process this frame
        for (y=0 ; y<H ; ++y) for (x=0 ; x<W ; ++x)

{
   
printf("Encrypted message = ");


for(int a=0;a<3;a++){
    for (int o = 1; o <prt->KeyE; o++) {
                                         
         frames[y][x][a] = frame0[y][x][a]* frames[y][x][a];
        
    }
     frames[y][x][a]  = frames[y][x][a]  % prt->KeyN;
    
   
}

printf("\nDecrypted message (IT'S MAGIC TIME) = ");

for(int b=0;b<3;b++){
    for (int o1 = 1; o1 < prt->KeyD; o1++) {
                                         
         frames[y][x][b] = frame0[y][x][b]* frames[y][x][b];
        
    }
     frames[y][x][b]  = frames[y][x][b]  % prt->KeyN;}
    
   
}





 // Write this frame to the output pipe
        fwrite(frames, 1, H*W*3, pipeout);
   // for(int r=0; r<strlen(k); r++){
      //  l[r]=prt2->m[r];
    //}
//printf("\n%s\n", l);

}
    return 0;
}

int CreatingExponent(struct Keys *a, struct Values *b) {
    a->KeyE=3;
    b->k=1;

    int loop=1;
    while(loop==1) {
        a->KeyD =b->k * b->FN+1;
        if (a->KeyD % a->KeyE == 0) {
            a->KeyD = a->KeyD / a->KeyE;
            printf("Number of Second Public Key Exponent(e) = %d\n", a->KeyE);
            loop=0;
        } else {
        b->k++;
            if(b->k>20){
                a->KeyE=a->KeyE+2;
                b->k=1;
                if(b->p-1%a->KeyE!=0 & b->q-1%a->KeyE!=0){
                }
                else {
                    a->KeyE=a->KeyE+2;
                }}  }}
    return 0;
}
