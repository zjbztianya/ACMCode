// Color Representation Conversion.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define ESP 1e-15
double sl,sv,v,l,r,g,b,h;
void  HSV_RGB()
{
    double c,hh,m,g1,b1,r1,x;
    c=v*sv;
    hh=h/60.0;
    x=c*(1-fabs(fmod(hh,2)-1));
    if(hh+ESP<1)        r1=c,g1=x,b1=0;
    else if(hh+ESP<2)   r1=x,g1=c,b1=0;
    else if(hh+ESP<3)   r1=0,g1=c,b1=x;
    else if(hh+ESP<4)   r1=0,g1=x,b1=c;
    else if(hh+ESP<5)   r1=x,g1=0,b1=c;
    else                r1=c,g1=0,b1=x;
    m=v-c;
    r=(r1+m)*255.0;
    g=(g1+m)*255.0;
    b=(b1+m)*255.0;
}
void  HSL_RGB()
{
    double c,hh,m,g1,b1,r1,x;
    c=(1-fabs(2*l-1))*sl;
    hh=h/60.0;
    x=c*(1-fabs(fmod(hh,2)-1));
    if(hh+ESP<1)        r1=c,g1=x,b1=0;
    else if(hh+ESP<2)   r1=x,g1=c,b1=0;
    else if(hh+ESP<3)   r1=0,g1=c,b1=x;
    else if(hh+ESP<4)   r1=0,g1=x,b1=c;
    else if(hh+ESP<5)   r1=x,g1=0,b1=c;
    else                r1=c,g1=0,b1=x;
    m=l-0.5*c;
    r=(r1+m)*255.0;
    g=(g1+m)*255.0;
    b=(b1+m)*255.0;
}
void RGB_HSV_HSL()
{
    double r1,g1,b1,maxs,mins;
    r1=r/255.0;
    g1=g/255.0;
    b1=b/255.0;
    maxs=max(max(r1,g1),b1);
    mins=min(min(r1,g1),b1);
    if(maxs==mins)
        h=0;
    else if(maxs==r1&&g1>=b1)
        h=60.0*(g1-b1)/(double)(maxs-mins);
    else if(maxs==r1&&g1<b1)
        h=60.0*(g1-b1)/(double)(maxs-mins)+360;
    else if(maxs==g1)
        h=60.0*(b1-r1)/(double)(maxs-mins)+120;
    else if(maxs==b1)
        h=60.0*(r1-g1)/(double)(maxs-mins)+240;
    l=0.5*(maxs+mins);
    if(fabs(l)<ESP||maxs==mins) sl=0;
    else if(l>ESP&&l<0.5+ESP)
        sl=(maxs-mins)/2/l;
    else
        sl=(maxs-mins)/(2-(maxs+mins));
    if(fabs(maxs)<ESP)
        sv=0;
    else
        sv=1-mins/maxs;
    v=maxs;
}
int main()
{
    string s1,s2;
    while(cin>>s1)
    {
        cin>>s2;
        if(s1=="RGB")
        {
            if(s2=="HSL")
            {
                char ch1,ch2;
                scanf("%lf%lf%c%lf%c",&h,&sl,&ch1,&l,&ch2);
                sl/=100.0;
                l/=100.0;
                HSL_RGB();
                printf("RGB %.0lf %.0lf %.0lf\n",r,g,b);
            }
            else if(s2=="HSV")
            {
                char ch1,ch2;
                scanf("%lf%lf%c%lf%c",&h,&sv,&ch1,&v,&ch2);
                sv/=100.0;
                v/=100.0;
                HSV_RGB();
                printf("RGB %.0lf %.0lf %.0lf\n",r,g,b);
            }
            else
            {
                scanf("%lf%lf%lf",&r,&g,&b);
                printf("RGB %.0lf %.0lf %.0lf\n",r,g,b);
            }
        }
        else if(s1=="HSL")
        {
            if(s2=="RGB")
            {
                scanf("%lf%lf%lf",&r,&g,&b);
                RGB_HSV_HSL();
                double ss=sl*100.0;
                double ll=l*100.0;
                printf("HSL %.0lf %.0lf%% %.0lf%%\n",h,ss,ll);
            }
            else if(s2=="HSV")
            {
                char ch1,ch2;
                scanf("%lf%lf%c%lf%c",&h,&sv,&ch1,&v,&ch2);
                sv/=100.0;
                v/=100.0;
                HSV_RGB();
                RGB_HSV_HSL();
                double ss=sl*100.0;
                double ll=l*100.0;
                printf("HSL %.0lf %.0lf%% %.0lf%%\n",h,ss,ll);
            }
            else
            {
                char ch1,ch2;
                scanf("%lf%lf%c%lf%c",&h,&sl,&ch1,&l,&ch2);
                printf("HSL %.0lf %.0lf%% %.0lf%%\n",h,sl,l);
            }
        }
        else
        {
            if(s2=="RGB")
            {
                scanf("%lf%lf%lf",&r,&g,&b);
                RGB_HSV_HSL();
                double ss=sv*100.0,vv=v*100.0;
                printf("HSV %.0lf %.0lf%% %.0lf%%\n",h,ss,vv);
            }
            else if(s2=="HSV")
            {
                char ch1,ch2;
                scanf("%lf%lf%c%lf%c",&h,&sv,&ch1,&v,&ch2);
                printf("HSV %.0lf %.0lf%% %.0lf%%\n",h,sv,v);
            }
            else
            {
                char ch1,ch2;
                scanf("%lf%lf%c%lf%c",&h,&sl,&ch1,&l,&ch2);
                sl/=100.0;
                l/=100.0;
                HSL_RGB();
                RGB_HSV_HSL();
                double ss=sv*100.0,vv=v*100.0;
                printf("HSV %.0lf %.0lf%% %.0lf%%\n",h,ss,vv);
            }
        }
    }
    return 0;
}
