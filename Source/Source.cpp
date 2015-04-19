#include<simplecpp>
#include <stdio.h>
#include <random>
#include <chrono>

/******************************ULTIMATE TIC TAC TOE***************************************************************************************/

namespace utt{

int box[9][9], bigbox[9];

void cross ( int x, int y ) {                                           //Creates a cross in the selected Box.
    int a = x/70, b=y/70;
    int c = a*70 + 8, d = b*70 + 8;
    int e = (a+1)*70 - 8, f = (b+1)*70 - 8;
    int g = (a+1)*70 - 8, h = b*70 + 8;
    int i = a*70 + 8, j = (b+1)*70 - 8;
    Line lc1(c,d,e,f); Line lc2(g,h,i,j); lc1.imprint(); lc2.imprint();
}

void circle ( int x, int y ) {                                          //Creates a circle in the selected Box.
    int a = x/70, b=y/70;
    int c = a*70 + 35, d = b*70 + 35;
    Circle c1(c,d,27);c1.imprint();
    }

int assignPrimBoxNo(int a, int b ){                                     //Assigns the Big box no. in which the selected small box lies.
     if (a<=2         && b<=2) {return 0;}
     if (a>=3 && a<=5 && b<=2) {return 1;}
     if (a>=6         && b<=2) {return 2;}
     if (a<=2         && b>=3 && b<=5) {return 3;}
     if (a>=3 && a<=5 && b>=3 && b<=5) {return 4;}
     if (a>=6         && b>=3 && b<=5) {return 5;}
     if (a<=2         && b>=6) {return 6;}
     if (a>=3 && a<=5 && b>=6) {return 7;}
     if (a>=6         && b>=6) {return 8;}
}

int assignSubBoxNo (int a, int b ){                                     //Assigns the Small Box no.
    int k=0, subbox[9][9];
    for(int i=0;i<3;i=i+1){
        for(int j=0;j<3;j=j+1){
            for(int l=i;l<9;l=l+3){
                for(int m=j;m<9;m=m+3){
                    subbox[l][m] = k;
                    }
                }
            k=k+1;
            }
        }
    return subbox[a][b];
}

bool checkBoxFull(int a){                                               //Checks if the Big Box is full.
    if(box[a][0] == 2 ||
       box[a][1] == 2 ||
       box[a][2] == 2 ||
       box[a][3] == 2 ||
       box[a][4] == 2 ||
       box[a][5] == 2 ||
       box[a][6] == 2 ||
       box[a][7] == 2 ||
       box[a][8] == 2
       ) return false;
    else return true;
}

bool checkWinPlayer1 ( int a ){                                         //Checks if Player 1 has won a big box.
if ((box[a][0] == box[a][1] && box[a][1] == box[a][2] && box[a][2] == 1) ||
    (box[a][3] == box[a][4] && box[a][4] == box[a][5] && box[a][5] == 1) ||
    (box[a][6] == box[a][7] && box[a][7] == box[a][8] && box[a][8] == 1) ||
    (box[a][0] == box[a][3] && box[a][3] == box[a][6] && box[a][6] == 1) ||
    (box[a][1] == box[a][4] && box[a][4] == box[a][7] && box[a][7] == 1) ||
    (box[a][2] == box[a][5] && box[a][5] == box[a][8] && box[a][8] == 1) ||
    (box[a][0] == box[a][4] && box[a][4] == box[a][8] && box[a][8] == 1) ||
    (box[a][2] == box[a][4] && box[a][4] == box[a][6] && box[a][6] == 1)
   ) return true;
else return false;
}

bool checkWinPlayer2 ( int a ){                                         //Checks if Player 2 has won a big box.
if ((box[a][0] == box[a][1] && box[a][1] == box[a][2] && box[a][2] == 0) ||
    (box[a][3] == box[a][4] && box[a][4] == box[a][5] && box[a][5] == 0) ||
    (box[a][6] == box[a][7] && box[a][7] == box[a][8] && box[a][8] == 0) ||
    (box[a][0] == box[a][3] && box[a][3] == box[a][6] && box[a][6] == 0) ||
    (box[a][1] == box[a][4] && box[a][4] == box[a][7] && box[a][7] == 0) ||
    (box[a][2] == box[a][5] && box[a][5] == box[a][8] && box[a][8] == 0) ||
    (box[a][0] == box[a][4] && box[a][4] == box[a][8] && box[a][8] == 0) ||
    (box[a][2] == box[a][4] && box[a][4] == box[a][6] && box[a][6] == 0)
   ) return true;
else return false;
}

void bigBoxWon( int bigboxno, int playerno, Line &lw1, Line &lw2, Circle &cw1){     //Makes a cross or a circle if a player has won a box
    if(playerno == 1){
        if (bigboxno==0){lw1 = {10,10,200,200};lw2 = {10,200,200,10};}
        if (bigboxno==1){lw1 = {220,10,410,200};lw2 = {220,200,410,10};}
        if (bigboxno==2){lw1 = {430,10,620,200};lw2 = {430,200,620,10};}
        if (bigboxno==3){lw1 = {10,220,200,410};lw2 = {10,410,200,220};}
        if (bigboxno==4){lw1 = {220,220,410,410};lw2 = {220,410,410,220};}
        if (bigboxno==5){lw1 = {430,220,620,410};lw2 = {430,410,620,220};}
        if (bigboxno==6){lw1 = {10,430,200,620};lw2 = {10,620,200,430};}
        if (bigboxno==7){lw1 = {220,430,410,620};lw2 = {220,620,410,430};}
        if (bigboxno==8){lw1 = {430,430,620,620};lw2 = {430,620,620,430};}
        return;
    }
    if(playerno == 2){
        if (bigboxno==0){cw1 = {105,105,95};}
        if (bigboxno==1){cw1 = {315,105,95};}
        if (bigboxno==2){cw1 = {525,105,95};}
        if (bigboxno==3){cw1 = {105,315,95};}
        if (bigboxno==4){cw1 = {315,315,95};}
        if (bigboxno==5){cw1 = {525,315,95};}
        if (bigboxno==6){cw1 = {105,525,95};}
        if (bigboxno==7){cw1 = {315,525,95};}
        if (bigboxno==8){cw1 = {525,525,95};}
    }
}

bool checkGameWin ( int playerno ) {                                                    //Checks if a player has won a game.
    if(playerno == 1){
        if ((bigbox[0] == bigbox[1] && bigbox[1] == bigbox[2] && bigbox[2] == 1) ||
            (bigbox[3] == bigbox[4] && bigbox[4] == bigbox[5] && bigbox[5] == 1) ||
            (bigbox[6] == bigbox[7] && bigbox[7] == bigbox[8] && bigbox[8] == 1) ||
            (bigbox[0] == bigbox[3] && bigbox[3] == bigbox[6] && bigbox[6] == 1) ||
            (bigbox[1] == bigbox[4] && bigbox[4] == bigbox[7] && bigbox[7] == 1) ||
            (bigbox[2] == bigbox[5] && bigbox[5] == bigbox[8] && bigbox[8] == 1) ||
            (bigbox[0] == bigbox[4] && bigbox[4] == bigbox[8] && bigbox[8] == 1) ||
            (bigbox[2] == bigbox[4] && bigbox[4] == bigbox[6] && bigbox[6] == 1)
           ) return true;
        else return false;
        }
    if(playerno == 2){
        if ((bigbox[0] == bigbox[1] && bigbox[1] == bigbox[2] && bigbox[2] == 0) ||
            (bigbox[3] == bigbox[4] && bigbox[4] == bigbox[5] && bigbox[5] == 0) ||
            (bigbox[6] == bigbox[7] && bigbox[7] == bigbox[8] && bigbox[8] == 0) ||
            (bigbox[0] == bigbox[3] && bigbox[3] == bigbox[6] && bigbox[6] == 0) ||
            (bigbox[1] == bigbox[4] && bigbox[4] == bigbox[7] && bigbox[7] == 0) ||
            (bigbox[2] == bigbox[5] && bigbox[5] == bigbox[8] && bigbox[8] == 0) ||
            (bigbox[0] == bigbox[4] && bigbox[4] == bigbox[8] && bigbox[8] == 0) ||
            (bigbox[2] == bigbox[4] && bigbox[4] == bigbox[6] && bigbox[6] == 0)
           ) return true;
        else return false;
        }
}

bool drawCheck(){                                                                   //Checks if the game is a draw.
    for(int i=0;i<9;i++){
        if(bigbox[i]==2)return false;
        }
    return true;
}

void utt(){                                                                         //Main Ultimate Tic Tac Toe.

for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
        box[i][j] = 2;
        }
    bigbox[i] = 2;
    }

Line l1(70,0,70,630);                                                               //Grid formation
Line l2(140,0,140,630);
Line l31(208,0,208,630);Line l32(209,0,209,630);Line l33(211,0,208,630);Line l34(212,0,212,630);
Line l4(280,0,280,630);
Line l5(350,0,350,630);
Line l61(418,0,418,630);Line l62(419,0,419,630);Line l63(421,0,421,630);Line l64(422,0,422,630);
Line l7(490,0,490,630);
Line l8(560,0,560,630);

Line lh1(0,70,630,70);
Line lh2(0,140,630,140);
Line lh31(0,208,630,208);Line lh32(0,209,630,209);Line lh33(0,211,630,211);Line lh34(0,212,630,212);
Line lh4(0,280,630,280);
Line lh5(0,350,630,350);
Line lh61(0,418,630,418);Line lh62(0,419,630,419);Line lh63(0,421,630,421);Line lh64(0,422,630,422);
Line lh7(0,490,630,490);
Line lh8(0,560,630,560);

Rectangle r[9];                                                             //Rectangles are used for each big box so that if it is won, it can be cleared
r[0] = {105,105,210,210};
r[1] = {315,105,210,210};
r[2] = {525,105,210,210};
r[3] = {105,315,210,210};
r[4] = {315,315,210,210};
r[5] = {525,315,210,210};
r[6] = {105,525,210,210};
r[7] = {315,525,210,210};
r[8] = {525,525,210,210};

for(int i=0;i<9;i++){
    r[i].setColor(COLOR("white"),true);
    }

Line l3(210,0,210,630);
Line l6(420,0,420,630);
Line lh3(0,210,630,210);
Line lh6(0,420,630,420);
Line lh9(0,630,630,630);


int userclick, x, y, xequiv, yequiv, MainBoxNo=10, primboxno1, subboxno1, primboxno2, subboxno2, cntlw=0, cntcw=0;
bool check;
Line lw1[5],lw2[5];
Circle cw1[5];
Text text;
char str[100];int n;

do{

    if ( MainBoxNo == 10)  n=sprintf(str,"Player 1, please select a box within any of the Primary Boxes.");
    else                   n=sprintf(str,"Player 1, please select a box within Primary Box No %d",MainBoxNo+1);
    text = {315,665,str};

    do{
       check = false;
       userclick = getClick();
       x = userclick/65536; y = userclick%65536;
       xequiv = (x/70); yequiv=(y/70);
       primboxno1 = assignPrimBoxNo(xequiv,yequiv);
       subboxno1 = assignSubBoxNo(yequiv,xequiv);

       if ( MainBoxNo != 10 ){if (primboxno1 != subboxno2) {check = true;}}     //Checks if player plays according to rules
       if ( bigbox[primboxno1] != 2 ) {check = true;}                           //Checks if the big box has already been won or not.
       if ( box[primboxno1][subboxno1] != 2){check = true;}                     //Checks if the small box has already been selected or not.
       if ( y > 630 ) {check = true;}                                           //Checks if the user doesnt click in text area.
       }
    while (check);

    cross(x,y);
    box[primboxno1][subboxno1] = 1;
    if (checkWinPlayer1(primboxno1)){
                                     bigbox[primboxno1] = 1;
                                     r[primboxno1].setFill(true);
                                     bigBoxWon(primboxno1,1,lw1[cntlw],lw2[cntlw],cw1[cntcw]);
                                     lw1[cntlw].imprint();lw2[cntlw].imprint();cntlw++;}

    if(checkBoxFull(primboxno1)){bigbox[primboxno1]=3;}
    if(checkGameWin(1)){text = {315,665,"PLAYER 1 WINS"};wait(5); return ;}
    if(drawCheck()){text = {315,665,"THE GAME IS A DRAW"};wait(5);return ;}

    MainBoxNo = subboxno1;

    if(bigbox[subboxno1] != 2){MainBoxNo = 10;}


    //Player 2 chance
    if ( MainBoxNo == 10)  n=sprintf(str,"Player 2, please select a box within any of the Primary Boxes.");
    else                   n=sprintf(str,"Player 2, please select a box within Primary Box No %d",MainBoxNo+1);
    text = {315,665,str};
    do{
       check = false;
       userclick = getClick();
       x = userclick/65536; y = userclick%65536;
       xequiv = (x/70); yequiv=(y/70);
       primboxno2 = assignPrimBoxNo(xequiv,yequiv);
       subboxno2 = assignSubBoxNo(yequiv,xequiv);

       if ( MainBoxNo != 10 ){if (primboxno2 != subboxno1) {check = true;}}
       if ( bigbox[primboxno2] != 2 ) {check = true;}
       if ( box[primboxno2][subboxno2] != 2){check = true;}
       if ( y > 630 ) {check = true;}
       }
    while (check);

    circle(x,y);
    box[primboxno2][subboxno2] = 0;
    if (checkWinPlayer2(primboxno2)){
                                     bigbox[primboxno2] = 0;
                                     r[primboxno2].setFill(true);
                                     bigBoxWon(primboxno2,2,lw1[cntlw],lw2[cntlw],cw1[cntcw]);
                                     cw1[cntcw].imprint();cntcw++;
                                     }

    if(checkBoxFull(primboxno2)){bigbox[primboxno2]=3;}
    if(checkGameWin(2)){text = {315,665,"PLAYER 2 WINS"};wait(5); return;}
    if(drawCheck()){text = {315,665,"THE GAME IS A DRAW"};wait(5);return;}

    MainBoxNo = subboxno2;

    if(bigbox[subboxno2] != 2){MainBoxNo = 10;}


}while(true);
wait(8);
}

}

/******************************************************************************************************************************************************************/

/**************************************************SINGLE PLAYER SIMPLE TIC TAC TOE********************************************************************************/

namespace stt{

int playermagicno[5], compmagicno[4];

void cross ( int x, int y ) {                                                           //Creates a cross in the selected Box.
    int a = x/210, b=y/210;
    int c = a*210 + 10, d = b*210 + 10;
    int e = (a+1)*210 - 10, f = (b+1)*210 - 10;
    int g = (a+1)*210 - 10, h = b*210 + 10;
    int i = a*210 + 10, j = (b+1)*210 - 10;
    Line lc1(c,d,e,f); Line lc2(g,h,i,j); lc1.imprint(); lc2.imprint();
}

void circle ( int a ) {                                                                 //Creates a circle in the selected Box.
    Circle c1;
    if (a==8) c1={105,105,95};
    if (a==3) c1={315,105,95};
    if (a==4) c1={525,105,95};
    if (a==1) c1={105,315,95};
    if (a==5) c1={315,315,95};
    if (a==9) c1={525,315,95};
    if (a==6) c1={105,525,95};
    if (a==7) c1={315,525,95};
    if (a==2) c1={525,525,95};
    c1.imprint();
}

int assignprimboxno(int a, int b ){                                                     //Assigns the Magic no.
     if (a<=210           && b<=210) {return 8;}
     if (a>=210 && a<=420 && b<=210) {return 3;}
     if (a>=420           && b<=210) {return 4;}
     if (a<=210           && b>=210 && b<=420) {return 1;}
     if (a>=210 && a<=420 && b>=210 && b<=420) {return 5;}
     if (a>=420           && b>=210 && b<=420) {return 9;}
     if (a<=210           && b>=420) {return 6;}
     if (a>=210 && a<=420 && b>=420) {return 7;}
     if (a>=420           && b>=420) {return 2;}
}

int randomno(int a[]){                                                                  //Creates a random no. using system clock.
    do{
        unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();

        // create source of randomness, and initialize it with non-deterministic seed
        mt19937 eng (seed1);

        // a distribution that takes randomness and produces values in specified range
        uniform_int_distribution<> dist(1,9);

        int randomno = dist(eng);
        for(int i=0;a[i]!=-1;i++){
            if(randomno == a[i])return randomno;
            }
    }while(true);
}

int compplay ( int playermagicno[], int compmagicno[], int moveno ){                            //Computer's Play

                for(int i=0;i<moveno-1;i++){                                                    //Checks if it can win
                    for(int j=0;j<moveno-1;j++){
                        if(i==j)continue;
                        int k = 15 - compmagicno[i] - compmagicno[j];
                        bool check=true;
                        if(k<1 || k>9)check = false;
                        for(int l=0;l<moveno;l++){
                            if(k == playermagicno[l]){check = false;break;}
                            }
                        for(int l=0;l<moveno-1;l++){
                            if(k == compmagicno[l]){check = false;break;}
                            }
                        if(check){return k;}
                        }
                    }

                for(int i=0;i<moveno;i++){                                                  //Checks if it can block opponent's win
                    for(int j=0;j<moveno;j++){
                        if(i==j)continue;
                        int k = 15 - playermagicno[i] - playermagicno[j];
                        bool check=true;
                        if(k<1 || k>9)check = false;
                        for(int l=0;l<moveno;l++){
                            if(k == playermagicno[l]){check = false;break;}
                            }
                        for(int l=0;l<moveno-1;l++){
                            if(k == compmagicno[l]){check = false;break;}
                            }
                        if(check){return k;}
                        }
                    }

    if (playermagicno[0] != 5){

             if (moveno == 1){
                return 5;
                }
        else if (moveno == 2){
                     if((playermagicno[0] == 3 && playermagicno[1] == 1) || (playermagicno[0] == 1 && playermagicno[1] == 3)){int a[]={8,4,6,-1};return randomno(a);}
                else if((playermagicno[0] == 3 && playermagicno[1] == 9) || (playermagicno[0] == 9 && playermagicno[1] == 3)){int a[]={8,4,2,-1};return randomno(a);}
                else if((playermagicno[0] == 1 && playermagicno[1] == 7) || (playermagicno[0] == 7 && playermagicno[1] == 1)){int a[]={8,6,2,-1};return randomno(a);}
                else if((playermagicno[0] == 7 && playermagicno[1] == 9) || (playermagicno[0] == 9 && playermagicno[1] == 7)){int a[]={6,4,2,-1};return randomno(a);}
                else {
                       bool check;int randno;
                       do{
                           check = false;
                           int allowednos[] = {3,1,9,7,-1};
                           randno = randomno(allowednos);
                           int k = 10 - randno;
                           if(playermagicno[0] == k || playermagicno[1] == k){check = true;}
                           } while(check);
                       return randno;
                     }
                }
        else {
                int allowednos[] = {8,3,4,1,9,6,7,2,-1};
                int k = randomno(allowednos);
                return k;
             }

        }

        else {
                if (moveno == 1 || moveno == 2){
                    int allowednos[] = {8,4,6,2,-1};
                    int k = randomno(allowednos);
                    return k;
                    }

                else {
                        int allowednos[] = {8,3,4,1,9,6,7,2,-1};
                        int k = randomno(allowednos);
                        return k;

                     }
             }

}

bool checkwin ( char x, int moveno){                                                //Checks if Player or Computer has won.
    if(x == 'p'){
        for(int i=0;i<moveno;i++){
            for(int j=0;j<moveno;j++){
                for(int k=0;k<moveno;k++){
                    if(i==j || j==k || i==k)continue;
                    if(playermagicno[i] + playermagicno[j] + playermagicno[k] == 15)return true;
                    }
                }
            }
        return false;
        }
    if(x == 'c'){
        for(int i=0;i<moveno;i++){
            for(int j=0;j<moveno;j++){
                for(int k=0;k<moveno;k++){
                    if(i==j || j==k || i==k)continue;
                    if(compmagicno[i] + compmagicno[j] + compmagicno[k] == 15)return true;
                    }
                }
            }
        return false;
        }
    }

int stt(){                                                                              //Main Simple Tic Tac Toe

Line l1(210,0,210,630);
Line l2(420,0,420,630);
Line l3(0,210,630,210);
Line l4(0,420,630,420);
Line l5(0,630,630,630);

int userclick, x, y, moveno=1;
bool check; Text text;


do {
    //Player's turn
    text = {315,665,"Please select a box"};
    do{
        check = false;
        userclick = getClick();
        x = userclick/65536; y = userclick%65536;
        playermagicno[moveno-1] = assignprimboxno(x,y);

        for(int i=0;i<moveno-1;i++){
            if(playermagicno[moveno-1] == playermagicno[i] || playermagicno[moveno-1] == compmagicno[i]) {check = true;break;}
            }
      } while(check);

    cross(x,y);

    if(checkwin('p',moveno)){text = {315,665,"PLAYER WINS."};wait(5);return 0;}
    if(moveno == 5){text = {315,665,"THE GAME IS A DRAW"};wait(5);return 0;}

    //Computer's turn
    text = {315,665,"Computer's turn..."};
    do{
        check = false;
        int temporaryvar = compplay ( playermagicno, compmagicno, moveno );
        compmagicno[moveno-1] = temporaryvar;

        for(int i=0;i<moveno-1;i++){
            if(compmagicno[moveno-1] == playermagicno[i] || compmagicno[moveno-1] == compmagicno[i] || compmagicno[moveno-1] == playermagicno[moveno-1]) {check = true;break;}
            }
      } while(check);

    circle(compmagicno[moveno-1]);
    if(checkwin('c',moveno)){text = {315,665,"COMPUTER WINS."};wait(5);return 0;}
    moveno++;

   }while(true);

}

}

/*************************************************************************************************************************************************************************************************/

main_program{

initCanvas("Tic Tac Toe",630,700);
bool sttcheck = false, uttcheck = false;

{
    Text t1(315,400,"Single Player Simple Tic Tac Toe");
    Rectangle r1(315,400,textWidth("Single Player Simple Tic Tac Toe")+10,textHeight()+10);

    Text t2(315,450,"Two Player Ultimate Tic Tac Toe");
    Rectangle r2(315,450,textWidth("Two Player Ultimate Tic Tac Toe")+10,textHeight()+10);

    Line l1(45,100,45,200);                                 //t
    Line l2(10,100,80,100);

    Line l3(95,100,95,200);                                 //i

    Line l4(235,100,235,200);                               //t
    Line l5(200,100,270,100);

    Line l6(270,200,300,100);                               //a
    Line l7(330,200,300,100);
    Line l8(285,150,315,150);

    Line l9 (460,100,460,200);                              //t
    Line l10(425,100,495,100);

    Line l11(570,100,570,200);                              //e
    Line l12(570,100,620,100);
    Line l13(570,150,610,150);
    Line l14(570,200,620,200);

    ellipse(145,150,45,315,30,50);                          //c
    ellipse(370,150,45,315,30,50);                          //c
    ellipse(525,150,0,360,30,50);                           //0

    bool check;

    do{
        check=true;

        int userclick = getClick();
        int x = userclick/65536, y = userclick%65536;


        if(x>203 && x<427 && y>387 && y<413){
            check=false;sttcheck = true;
            }

        if(x>206 && x<424 && y>437 && y<463){
            check=false;uttcheck = true;
            }

    }while(check);
}

if(sttcheck == true){stt::stt();return 0;}
if(uttcheck == true){utt::utt();return 0;}

wait(1);
}
