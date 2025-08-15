#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void red() {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}

void reset() {
  printf("\033[0m");
}

int main()
{
  int i,l=1,k,m=1,cana=3,canb=3,canc=3;
    char kutucuk[50];
    int secim,krk,sut=1,oync=1;
    int kr[10];
    int saglam[11];
    int konuma=0,konumb=0,konumc=0;
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t----Welcome to the Broken Glass Game----");
    printf("\n\n\n\tPress <ENTER> to see the game rules");
    getchar();
    printf("\nOur game has a glass bridge consisting of 4 rows and 10 columns.\n");
    printf("Three players named 'A', 'B', and 'C' will try to cross the bridge by stepping on unbroken glass tiles to reach the 'FINISH' line.\n");                     // Game Rules
    printf("Each player has 3 lives. If a player steps on broken glass, they start over from the beginning and lose 1 life. A player with 0 lives cannot continue.\n");
    printf("\nPress <ENTER> to see the bridge...\n\n");
    getchar();
    for(i=0;i<10;i++)printf("\n");
    printf("\n");
    for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Column   ",i);}
    printf("\tFINISH\t\t LIVES : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            if(m<10){printf("|     %d      ",kutucuk[m]);}                                                                                                                          //BRIDGE DESIGN
            else
            printf("|    %d      ",kutucuk[m]);
            m+=4;       }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
    
    srand(time(NULL));
    
    
    for(l=1;l<100;l+=4)                                                                                                                                                             //GAME START
    {
        printf("\n\n\nPress <ENTER> to continue");
        getchar();
    for(i=0;i<10;i++)printf("\n");
        printf("\n\n%d. Player will choose a number from %d.column",oync,sut);
        secim=rand()% 4+l;
        krk=rand()% 4+l;
    
    if(secim==krk){                                                                                                                                                             //If player steps on broken glass
            kr[sut]=secim;
            
        printf("\n%d. Player jumped on glass number %d in column %d and the glass broke.",oync,secim,sut);
        if(oync==1){
            cana-=1;
            if(cana==0){printf("\n1. Player has no lives left and cannot continue...\n");}
            if(sut==2){
                konumb++;
            }
            if(sut>=3){
                konumb++;konumc++;printf("Players behind are advancing one step...");
            }
            
        }
        else if(oync==2){
            canb-=1;
            if(canb==0){printf("\n2. Player has no lives left and cannot continue...\n");}
            if(sut==2){
                konumc++;
            }
             if(sut>=3){
                konumc++;konuma++;printf("Players behind are advancing one step...");
            }
            
        }
        else {canc-=1;
            if(canc==0){printf("\n3. Player has no lives left and cannot continue...\n");}
            if(sut==2){
                konuma++;
            }
             if(sut>=3){
                konuma++;konumb++;printf("Players behind are advancing one step...");
            }
            
        }
        if(cana!=0 && oync==1){printf("\n\n1. Player will restart from the beginning and will play last...\n");konuma=0;}
        if(canb!=0 && oync==2){printf("\n\n2. Player will restart from the beginning and will play last...\n");konumb=0;}
        if(canc!=0 && oync==3){printf("\n\n3. Player will restart from the beginning and will play last...\n");konumc=0;}
        oync+=1;
        
         if(sut>=3){
                if(sut-konuma>1 && sut-konumb>1 && sut-konumc>1 ){
                if(oync==1&&cana!=0){printf("\nCharacters are returning to the last safe point without stepping on broken glass and maintaining order (%d STEPS)",sut-konuma-1);konumc+=sut-1-konuma;konumb+=sut-1-konuma;konuma=sut-1;}
                if(oync==2&&canb!=0){printf("\nCharacters are returning to the last safe point without stepping on broken glass and maintaining order (%d STEPS)",sut-konumb-1);konuma+=sut-1-konumb;konumc+=sut-1-konumb;konumb=sut-1;}
                if(oync==3&&canc!=0){printf("\nCharacters are returning to the last safe point without stepping on broken glass and maintaining order (%d STEPS)",sut-konumc-1);konumb+=sut-1-konumc;konuma+=sut-1-konumc;konumc=sut-1;}
                }}
                
        
        do{secim=rand() % 4+l;}while(secim==krk);                                                                                                           //Next player jumps on any unbroken glass
        saglam[sut]=secim;
        if(cana==0 && oync==1){oync+=1;}
        if(canb==0 && oync==2){oync+=1;}
        if(canc==0 && oync==3){oync+=1;}
        if(oync>3 && cana!=0 ){oync=1;}
        if(oync>3 && cana==0 ){oync=2;}
        printf("\nNow it's %d. Player's turn.\n",oync);
        printf("\n\n%d. Player successfully jumped on glass number %d in column %d.",oync,secim,sut);
        if(sut==1){
            if(oync==1)konuma++;
            if(oync==2)konumb++;
            if(oync==3)konumc++;
        }
                                                                                                                                                        //Players advancing one step
        if(sut==2){
            if(oync==1){konumb++;konuma++;}
        
            if(oync==2){konumc++;konumb++;}
        
            if(oync==3){konuma++;konumc++;printf("\nPlayer 1 is following by jumping on unbroken glass number %d in column %d\n\n",saglam[sut-1],sut-1);}
            if(oync!=3)printf("\nPlayer %d is following by jumping on unbroken glass number %d in column %d\n\n",oync+1,saglam[sut-1],sut-1);}
        
        if(sut>=3){
                konuma++;konumb++;konumc++;
                if(cana==0)konuma=0;
                if(canb==0)konumb=0;
                if(canc==0)konumc=0;
                if(oync==1&&canb!=0&&canc!=0){printf("\n\nPlayer 2 is moving to glass number %d in column %d, Player 3 is moving to glass number %d in column %d\n",saglam[konumb],konumb,saglam[konumc],konumc);}
                if(oync==2&&cana!=0&&canc!=0){printf("\n\nPlayer 3 is moving to glass number %d in column %d, Player 1 is moving to glass number %d in column %d\n",saglam[konumc],konumc,saglam[konuma],konuma);}
                if(oync==3&&canb!=0&&cana!=0){printf("\n\nPlayer 1 is moving to glass number %d in column %d, Player 2 is moving to glass number %d in column %d\n",saglam[konuma],konuma,saglam[konumb],konumb);}
                if(oync==1&&canc!=0&&cana==0){printf("\n\nPlayer 3 is moving to glass number %d in column %d\n",saglam[konumc],konumc);}
                if(oync==2&&canc!=0&&cana==0){printf("\n\nPlayer 3 is moving to glass number %d in column %d.\n",saglam[konumc],konumc);}
                if(oync==3&&canb!=0&&cana==0){printf("\n\nPlayer 2 is moving to glass number %d in column %d\n",saglam[konumb],konumb);}
        }
        
        printf("\n\n\nPress <ENTER> to see the bridge and players' lives after round %d",sut);                                                  //Show bridge status and lives after each round
        getchar();
    for(i=0;i<10;i++)printf("\n");
         printf("\n\n");
        for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Column   ",i);}
    printf("\tFINISH\t\t LIVES : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    m=1;
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            
            if(m==saglam[konuma]){
                if(cana>0){printf("|");yellow();printf("     A      ");reset();}
                else if(m>=10&&cana==0) printf("|    %d      ",kutucuk[m]);
                else if(m<10 &&cana==0) printf("|     %d      ",kutucuk[m]);
               }
            if(m==saglam[konumb]){
                if(canb>0){printf("|");yellow();printf("     B      ");reset();}
                else if(m>=10&&canb==0) printf("|    %d      ",kutucuk[m]);
                else if(m<10 &&canb==0) printf("|     %d      ",kutucuk[m]);
                
                }
            if(m==saglam[konumc]){
                if(canc>0){printf("|");yellow();printf("     C      ");reset();}
                else if(m>=10&&canc==0) printf("|    %d      ",kutucuk[m]);
                else if(m<10 &&canc==0) printf("|     %d      ",kutucuk[m]);
            }
            if(kr[1]==m || kr[2]==m || kr[3]==m || kr[4]==m || kr[5]==m || kr[6]==m || kr[7]==m || kr[8]==m || kr[9]==m || kr[10]==m) {printf("|");red();printf("     K      ");reset();}
            
            
            if(m<10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m ){printf("|     %d      ",kutucuk[m]);}                                                                                                              
            if(m>=10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && m>=10  && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m)
            printf("|    %d      ",kutucuk[m]);
            
            m+=4;      
            }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
        printf("\n");
        sut+=1;
    }
    else                                                                                                                                                                        //If player steps on unbroken glass
    {
        saglam[sut]=secim;
            printf("\n\n%d. Player successfully jumped on glass number %d in column %d and the glass didn't break.\n",oync,secim,sut);
            if(sut==1)konuma++;
            if(sut==2){if(oync==1){konumb++;konuma++;}
        if(oync==2){konumc++;konumb++;}
        if(oync==3){konuma++;konumc++;}
                printf("\nPlayer %d is following by jumping on unbroken glass number %d in column %d\n",oync+1,saglam[sut-1],sut-1);}
            if(sut>=3){
                konuma++;konumb++;konumc++;                                                                                                                                     //Players behind following
                if(cana==0)konuma=0;
                if(canb==0)konumb=0;
                if(canc==0)konumc=0;
                if(oync==1&&canb!=0&&canc!=0){printf("\n\nPlayer 2 is moving to glass number %d in column %d, Player 3 is moving to glass number %d in column %d\n",saglam[konumb],konumb,saglam[konumc],konumc);}
                if(oync==2&&cana!=0&&canc!=0){printf("\n\nPlayer 3 is moving to glass number %d in column %d, Player 1 is moving to glass number %d in column %d\n",saglam[konumc],konumc,saglam[konuma],konuma);}
                if(oync==3&&canb!=0&&cana!=0){printf("\n\nPlayer 1 is moving to glass number %d in column %d, Player 2 is moving to glass number %d in column %d\n",saglam[konuma],konuma,saglam[konumb],konumb);}
                if(oync==1&&canc!=0&&cana==0){printf("\n\nPlayer 3 is moving to glass number %d in column %d\n\n\n\n",saglam[konumc],konumc);}
                if(oync==2&&canc!=0&&cana==0){printf("\n\nPlayer 3 is moving to glass number %d in column %d.\n\n\n\n",saglam[konumc],konumc);}
                if(oync==3&&canb!=0&&cana==0){printf("\n\nPlayer 2 is moving to glass number %d in column %d\n\n\n\n",saglam[konumb],konumb);}}
                
                printf("\nPress <ENTER> to see the bridge...");
                getchar();
    for(i=0;i<10;i++)printf("\n");
             printf("\n\n");
                for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Column   ",i);}
    printf("\tFINISH\t\t LIVES : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    m=1;
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            
            if(m==saglam[konuma]){
                if(cana>0){printf("|");yellow();printf("     A      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                 if(m<10) printf("|     %d      ",kutucuk[m]);}
               }
            if(m==saglam[konumb]){
                if(canb>0){printf("|");yellow();printf("     B      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                if(m<10) printf("|     %d      ",kutucuk[m]);}
                }
            if(m==saglam[konumc]){
                if(canc>0){printf("|");yellow();printf("     C      ");reset();}
                else 
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                    if(m<10 ) printf("|     %d      ",kutucuk[m]);}
            }
            if(kr[1]==m || kr[2]==m || kr[3]==m || kr[4]==m || kr[5]==m || kr[6]==m || kr[7]==m || kr[8]==m || kr[9]==m || kr[10]==m) {printf("|");red();printf("     K      ");reset();}
            
            
            if(m<10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m ){printf("|     %d      ",kutucuk[m]);}                                                                                                              
            if( m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && m>=10  && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m)
            printf("|    %d      ",kutucuk[m]);
            
            m+=4;      
            }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
        printf("\n"); 
    sut+=1;
    }
     if(sut>10){                                                                                                                                            //If a player reaches the last column and wins...
    for(i=0;i<10;i++)printf("\n");
            printf("\n\nPlayer %d successfully reached the <FINISH> line and won the game",oync);
            printf("\n\nCONGRATULATIONS PLAYER %d",oync);
            
            if(sut==11){                                                                                                                                    //Final adjustment to prevent order disruption if mistaken in last column...
                if(sut-konuma>0 && sut-konumb>0 && sut-konumc>0 ){
                if(oync==1&&cana!=0&&konuma!=10){konumc+=sut-konuma-1;konumb+=sut-konuma-1;konuma=sut-1;}
                if(oync==2&&canb!=0&&konumb!=10){konuma+=sut-konumb-1;konumc+=sut-konumb-1;konumb=sut-1;}
                if(oync==3&&canc!=0&&konumc!=10){konumb+=sut-konumc-1;konuma+=sut-konumc-1;konumc=sut-1;}
                }}
                
                printf("\n\t\t\t----- FINAL BRIDGE STATUS -----");
            printf("\n\n");
                for(int i = 1; i <= 50;i++) {kutucuk[i]=i;}
    for(i=1;i<11;i++){printf("   %d.Column   ",i);}
    printf("\tFINISH\t\t LIVES : A = %d  B = %d  C = %d",cana,canb,canc);
    printf("\n");
    for(i=1;i<11;i++){
        printf("-------------");
    }
    printf("-\n");
    m=1;
    for(k=1;k<=4;k++){
        
        for(i=1;i<=10;i++){
            
            if(m==saglam[konuma]){
                if(cana>0){printf("|");yellow();printf("     A      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                 if(m<10) printf("|     %d      ",kutucuk[m]);}
               }
            if(m==saglam[konumb]){
                if(canb>0){printf("|");yellow();printf("     B      ");reset();}
                else
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                if(m<10) printf("|     %d      ",kutucuk[m]);}
                }
            if(m==saglam[konumc]){
                if(canc>0){printf("|");yellow();printf("     C      ");reset();}
                else 
                {if (m>=10) printf("|    %d      ",kutucuk[m]);
                    if(m<10 ) printf("|     %d      ",kutucuk[m]);}
            }
            if(kr[1]==m || kr[2]==m || kr[3]==m || kr[4]==m || kr[5]==m || kr[6]==m || kr[7]==m || kr[8]==m || kr[9]==m || kr[10]==m) {printf("|");red();printf("     K      ");reset();}
            
            
            if(m<10 && m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m ){printf("|     %d      ",kutucuk[m]);}                                                                                                              
            if( m!= saglam[konuma] && m!= saglam[konumb] && m!= saglam[konumc] && m>=10  && kr[1]!=m && kr[2]!=m && kr[3]!=m && kr[4]!=m && kr[5]!=m && kr[6]!=m && kr[7]!=m && kr[8]!=m && kr[9]!=m && kr[10]!=m)
            printf("|    %d      ",kutucuk[m]);
            
            m+=4;      
            }
        printf("|\tXXXXXX\n");
        m-=39;
        for(i=1;i<=10;i++){printf("-------------");}
        
        printf("-\n");}
        printf("\n"); 
            
            break;
            
        }
}
    printf("\n\t This game was created by K.S.U. student OMER CEVHER.\n\n Name-Surname         STUDENT NUMBER\n\n OMER CEVHER        : 21110131002\n\n");
    
}