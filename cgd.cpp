#include<iostream>
#include<math.h>
using namespace std;

//function to find Fl
float func (float pl,float pstar,float rhol){
         float gamma=1.4;
         float effl,al;
     if(pstar>pl){
         float a= 2/((gamma+1)*rhol);
         float b=((pl*(gamma-1)/(gamma+1))+pstar);
        float c=sqrt(a/b);
        effl=((pstar-pl)*c);
}
    else {
        gamma=1.4;
        float al=pow(((gamma*pl)/rhol),0.5);
        float a=((gamma-1)/(2*gamma));
        float b=(pow((pstar/pl),a)-1);
     effl=((2*al*b)/(gamma-1));   
}
return effl;
}


//function to find Fr
float func_1 (float pr,float pstar,float rhor){
       float gamma=1.4;
       float effr,ar;
   if(pstar>pr){
       float a= 2/((gamma+1)*rhor);
       float b=(pr*((gamma-1)/(gamma+1)))+pstar;
       float c=sqrt(a/b);
       effr=((pstar-pr)*c);
}
   else {
      gamma=1.4;
      float ar=pow(((gamma*pr)/rhor),0.5);
      float a=((gamma-1)/(2*gamma));
      float b=(pow((pstar/pr),a)-1);
      effr=((2*ar*b)/(gamma-1));   

}
return effr;
}


//function to find Fl dash
float func_2(float pl,float pstar, float rhol){
      float gamma =1.4;
      float al;
      float f_1;
    if(pstar>pl){
       float a=(((gamma-1)/(gamma+1))*pl)+pstar;
       float b= 2/((gamma+1)*rhol);
       f_1=(sqrt(b/a))*(1-((pstar-pl)/(2*a)));
    }
    else{
        float al=pow(((gamma*pl)/rhol),0.5);
        float a=((gamma+1)/(2*gamma));
        f_1=((pow((pl/pstar),a))/(rhol*al));
    }
    return f_1;
}

//function to find Fr dash
float func_3(float pr,float pstar, float rhor){
      float gamma =1.4;
      float ar;
      float f_2;
    if(pstar>pr){
        float a=(((gamma-1)/(gamma+1))*pr)+pstar;
        float b= 2/((gamma+1)*rhor);
        f_2=(sqrt(b/a))*(1-((pstar-pr)/(2*a)));
    }
    else{
        float ar=pow(((gamma*pr)/rhor),0.5);
        float a=((gamma+1)/(2*gamma));
        f_2=((pow((pr/pstar),a))/(rhor*ar));
    }
    return f_2;
}


//function to find F
float f1(float pl,float pr,float rhol,float rhor, float ul,float ur,float pstar){
    float a=(func(pl,pstar,rhol)+func_1(pr,pstar,rhor))+(ur)-(ul);
    return a;
}


//function to find F dash
float f1_dash(float pl,float pr,float rhol,float rhor, float ul,float ur,float pstar){
    float b=func_2(pl,pstar,rhol)+func_3(pr,pstar,rhor);
    return b;
}


//function to find u star
float u_star(float ul,float ur, float rhol, float rhor,float pl,float pr,float pstar){
 float a=(((ul)+(ur))/2)+(((func_1(pr,pstar,rhor))-func(pl,pstar,rhol))/2);
 return a;
}


//function to find rhol star
float rho_l_star(float rhol,float pstar,float pl){
   float gamma=1.4;
   float c;
   int z=1;
   if(pstar>pl){
      float a=((gamma-1)/(gamma+1));
      float b=(pstar/pl);
      c=(rhol*((a+b)/((a*b)+1)));
}
else{
    float a=(pstar/pl);
    float b=(z/gamma);
    c=(rhol*(pow(a,b)));
}
return c;
 }


   //function to find rhor star
float rho_r_star(float rhor,float pstar,float pr){
   float gamma=1.4;
   float c;
   int z=1;
   if(pstar>pr){
      float a=((gamma-1)/(gamma+1));
      float b=(pstar/pr);
      c=rhor*((a+b)/((a*b)+1));
}
else{
    float a=(pstar/pr);
    float b=(z/gamma);
    c=(rhor*(pow(a,b)));
}
return c;
   }

 float right(float ur, float pstar, float ustar,float pl, float ul,float pr, float rhol,float rhor){
     float gamma=1.4;
     float Sr,Rrh,Rrt;
     if(pstar>pr){
        cout<<"the right shock speed is"<<endl;
        float a=((gamma+1)/(2*gamma));
        float b=((gamma-1)/(2*gamma));
        float c=(pstar/pr);
        float ar=pow(((gamma*pr)/rhor),0.5);

        Sr=(ur+(ar*sqrt((a*c)+b)));
        return Sr;

     }
     else{
           cout<<"the speed of right rarefactions are"<<endl;
          float ar_star=pow(((gamma*pstar)/( rho_r_star(rhor,pstar,pr))),0.5);
          float ar=pow(((gamma*pr)/rhor),0.5);
          Rrh=(ur +ar);
          Rrt=((u_star(ul,ur,rhol,rhor,pl,pr,pstar))+ar_star);
          cout<<"value of Rrh:"<<Rrh<<endl;
          cout<<"value of Rlh:"<<Rrt<<endl;

          return 0;

     }
 }
 float left(float ur, float pstar, float ustar,float pl, float ul,float pr, float rhol,float rhor)
     {
     float gamma=1.4;
     float Sl,Rlh,Rlt;
     if(pstar<pl){
        cout<<"the speed of left rarefactions are"<<endl;
     float al=pow(((gamma*pl)/rhol),0.5);
     float al_star=pow(((gamma*pstar)/(rho_l_star(rhol,pstar,pl))),0.5);
     Rlh=(ul-al);
     Rlt=((u_star(ul,ur,rhol,rhor,pl,pr,pstar))-(al_star));
     cout<<"value of Rlh:"<<Rlh<<endl;
     cout<<"value of Rlt:"<<Rlt<<endl;

     return 0;
    }
    else{
        cout<<"the left shock speed is"<<endl;
        float a=((gamma+1)/(2*gamma));
        float b=((gamma-1)/(2*gamma));
        float c=(pstar/pl);
        float al=pow(((gamma*pl)/rhol),0.5);

        Sl=(ul-(al*sqrt((a*c)+b)));
        return Sl;
    }



     }


int main(){
float pstar,pl,pr,rhol,rhor,al,z,y,f,ustar,ul,ur,f_dash,pstar_new;
float gamma =1.4;
cout<<"enter the value of pl"<<endl;
cin>>pl;
cout<<"enter the value of pr"<<endl;
cin>>pr;
cout<<"enter the value of rhol"<<endl;
cin>>rhol;
cout<<"enter the value of rhor"<<endl;
cin>>rhor;
cout<<"enter the value of ul"<<endl;
cin>>ul;
cout<<"enter the value of ur"<<endl;
cin>>ur;

if(pl!=pr){
    pstar=(pl+pr)/2;cout<<"yes";
}
else{
    pstar=exp(-6);
    cout<<"output1;"<<pstar;cout<<"yes2";
}


cout<<"output of f_l:"<<func(pl,pstar,rhol)<<endl;
cout<<"output of f_r:"<<func_1(pr,pstar,rhor)<<endl;
cout<<"output of fdash_l:"<<func_2(pl,pstar,rhol)<<endl;
cout<<"output of fdash_r:"<<func_3(pr,pstar,rhor)<<endl;
 cout<<"output of F:"<<f1(pl,pr,rhol,rhor,ul,ur,pstar)<<endl;
 cout<<"output of Fdash:"<<f1_dash(pl,pr,rhol,rhor,ul,ur,pstar)<<endl;

// newton rapson to find pstar new
float error=1;
while(fabs(error)>0.0001)
{
    pstar_new = pstar - ( f1(pl,pr,rhol,rhor,ul,ur,pstar)/f1_dash(pl,pr,rhol,rhor,ul,ur,pstar));
    error = fabs(pstar_new - pstar);
    pstar=pstar_new;
}
    cout<<"value of pstar new:"<<pstar_new<<endl;

cout<<"value of ustar:"<<u_star(ul,ur,rhol,rhor,pl,pr,pstar_new)<<endl;
cout<<"value of rhol star:"<<rho_l_star(rhol,pstar,pl)<<endl;
cout<<"value of rhor star:"<<rho_r_star(rhor,pstar,pr)<<endl;
cout<<right(ur,pstar,ustar,pl,ul,pr,rhol,rhor)<<endl;
cout<<left(ur,pstar,ustar,pl,ul,pr,rhol,rhor)<<endl;
return 0;
}
