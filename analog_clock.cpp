#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include <process.h>

void draw(){
    setcolor(WHITE);
    circle(400,150,122);//For clock outer boundary
    circle(400,150,60);//For clock inner boundary


    //Clock Text
    settextstyle(0,HORIZ_DIR,2);
    outtextxy(380, 60, "XII");
    outtextxy(450, 70, "I");
    outtextxy(460, 105, "II");
    outtextxy(462, 140, "III");
    outtextxy(460, 180, "IV");
    outtextxy(440, 220, "V");
    outtextxy(380, 225, "VI");
    outtextxy(320, 220, "VII");
    outtextxy(290, 180, "VIII");
    outtextxy(305, 140, "IX");
    outtextxy(320, 105, "X");
    outtextxy(335, 75, "XI");


    line(400,0,200,100);//Roof Left
    line(400,0,600,100);//Roof Right
    line(250,75,250,300);//Left Boundary
    line(550,75,550,300);//Right Boundary
    line(550,300,250,300);//Floor

    //Pendulam Home
    line(250,300,250,500);//Left
    line(550,300,550,500);//Right
    line(550,500,250,500);//Floor

}

void pendulam(void *param){
    //setcolor(WHITE);
    setwritemode(XOR_PUT);

    int xp1=400, yp1=300, xp2=400, yp2=450, xp4, yp4, hp, kp;
    float t, r;
    while(1){
    //setcolor(WHITE);
    for(r=-45;r<45;r++){

            t=3.1416*r/180;
            hp=xp1;
            kp=yp1;
            xp4=abs(xp2*cos(t)-yp2*sin(t)-hp*cos(t)+kp*sin(t)+hp);
            yp4=abs(xp2*sin(t)+yp2*cos(t)-hp*sin(t)-kp*cos(t)+kp);
            line(xp1,yp1,xp4,yp4);
            circle(xp4,yp4,20);
            delay(15);
            line(xp1,yp1,xp4,yp4);
            circle(xp4,yp4,20);

        }
        //Loop for clockwise rotation of pendulam
        for(r=-45;r<45;r++){
            t=3.1416*r/180;
            hp=xp1;
            kp=yp1;
            xp4=abs(xp2*cos(-t)-yp2*sin(-t)-hp*cos(-t)+kp*sin(-t)+hp);
            yp4=abs(xp2*sin(-t)+yp2*cos(-t)-hp*sin(-t)-kp*cos(-t)+kp);
            line(xp1,yp1,xp4,yp4);
            circle(xp4,yp4,20);
            delay(15);
            line(xp1,yp1,xp4,yp4);
            circle(xp4,yp4,20);

        }
    }
}

void smh(void *param){
    setwritemode(XOR_PUT);
    int xs1=400, ys1=150, xs2=400, ys2=60, xs4, ys4, hs, ks, xm1=400, ym1=150, xm2=400, ym2=90, xm4, ym4, hm, km, xh1=400, yh1=150, xh2=400, yh2=110, xh4, yh4, hh, kh;
    float t,rs,t2,rm=0,rh=0, t3, m, h;

    printf("Enter minute(<=59): ");
    scanf("%f", &m);
    rm=m*6;

    printf("Enter hour: ");
    scanf("%f", &h);
    if(h==12){
        h=0;
    }
    rh=h*30;

    while(1){
        for(rh=h*30;rh<360;rh=rh+30){
            for(rm=m*6;rm<360;rm=rm+6){
                for(rs=0;rs<360;rs=rs+6){
                    hs=xs1;
                    ks=ys1;
                    t=3.1416*rs/180;
                    xs4=abs(xs2*cos(t)-ys2*sin(t)-hs*cos(t)+ks*sin(t)+hs);
                    ys4=abs(xs2*sin(t)+ys2*cos(t)-hs*sin(t)-ks*cos(t)+ks);
                    if(rs==180||rs==270){
                        xs4=xs4+1;
                        ys4=ys4+1;
                    }

                    hm=xm1;
                    km=ym1;
                    t2=3.1416*rm/180;
                    xm4=abs(xm2*cos(t2)-ym2*sin(t2)-hm*cos(t2)+km*sin(t2)+hm);
                    ym4=abs(xm2*sin(t2)+ym2*cos(t2)-hm*sin(t2)-km*cos(t2)+km);
                    if(rm==180||rm==270){
                        xm4=xm4+1;
                        ym4=ym4+1;
                    }

                    hh=xh1;
                    kh=yh1;
                    t3=3.1416*rh/180;
                    xh4=abs(xh2*cos(t3)-yh2*sin(t3)-hh*cos(t3)+kh*sin(t3)+hh);
                    yh4=abs(xh2*sin(t3)+yh2*cos(t3)-hh*sin(t3)-kh*cos(t3)+kh);
                    if(rh==180||rh==270){
                        xh4=xh4+1;
                        yh4=yh4+1;
                    }

                    line(xh1,yh1,xh4,yh4);//hour*/
                    line(xm1,ym1,xm4,ym4);//min
                    line(xs1,ys1,xs4,ys4);//sec
                    delay(1000);
                    line(xs1,ys1,xs4,ys4);//sec
                    line(xm1,ym1,xm4,ym4);//min
                    line(xh1,yh1,xh4,yh4);//hour*/

                }
                m=0;
            }
            h=0;
        }
        //h=0;
        //m=0;
    }

}

int main(){
    initwindow(800,600);
    HANDLE hThread1;
    HANDLE hThread2;

    draw();


        hThread1 = (HANDLE) _beginthread(pendulam, 0, 0);
        hThread2 = (HANDLE) _beginthread(smh, 0, 0);


    getch();
    closegraph();
    return 0;
}


