#include<iostream>
#include<string>
#include<math.h>
#include<cstdlib>

 using namespace std;




 class point{
	 float x;
	 float y;
 public:
     void equalpoint(point p)
     {
         x=p.x;
         y=p.y;
     }
     point()
     {
	     x=0;
	     y=0;
	 }
	 void setx(float a)
	 {
		 x=a;
	 }
	 float getx()
	 {
		 return x;
	 }
	  void sety(float a)
	 {
		 y=a;
	 }
	 float gety()
	 {
		 return y;
	 }
	 void print()
	 {
	     cout<<"("<<x<<","<<y<<")";
	 }
	 float slope(point p)
	 {
	     float m=(y-p.y)/(x-p.x);
	     return m;
	 }
	 int compare(point p)
	 {
	     if((x==p.x)&&(y==p.y))
         {
             return 1;
         }
         return 0;
	 }
	 float distance (point p)
	 {
	     float dis=sqrt(pow((x-p.x),2)+pow((y-p.y),2));
	     return dis;
	 }
	 float distance_from_line(point a,point b)
	 {
	     float m=a.slope(b);
	     float ubber=fabs(m*x+(-1)*y+((a.y)-m*(a.x)));
	     float lowwer=sqrt(pow(m,2)+1);
	     float t=ubber/lowwer;
	     return t;
	 }

 };
point midpoint(point a,point b);//because we use this function in polygon class
float MAX (float v[],int n);
float MIN(float v[],int n);
int is_on_line(point a,point p1,point p2);
int two_line_intersect(point a1,point b1,point a2,point b2);
point two_line_intersect_point(point a1,point b1,point a2,point b2);

 class polygon{
	 int NumberOfPoints;
	 point poly [100];
	 point poly_before_redundant[100];
	 int PolygonNumber;
	 int reaal;
 public:
     void setreaal(int n)
     {
         reaal=n;
     }
     int getreaal()
     {
         return reaal;
     }

	 void setpoly_before_redundant()
	 {
	     for(int i=0;i<NumberOfPoints;i++)
         {
            poly_before_redundant[i]=poly[i];
         }
	 }
	 void setNO_Points(int a)
	 {
		 NumberOfPoints=a;
	 }
	 int getNO_Points()
	 {
		 return NumberOfPoints;
	 }

	 void setPolyNum(int a)
	 {
		 PolygonNumber=a;
	 }
	 int getPolyNum()
	 {
		 return PolygonNumber;
	 }


	 void setpoint(point p,int a)
	 {
	 poly[a]=p;
	 }

	 point getpoint(int a)
	 {
	 return poly[a];
	 }
 point getpointbefore_redundant(int a)
	 {
	 return poly_before_redundant[a];
	 }
	 void print()
	 {
	     int n=NumberOfPoints;
	     for(int i=0;i<n;i++)
         {

             float x=poly[i].getx();
             float y=poly[i].gety();
             cout<<"("<<x<<","<<y<<")";
             if (i==(n-1))
             {
                 continue;
             }
                 cout<<",";
         }
	 }

	 int redun()
	 {
	     float m,n;
	     int count=0,z=0;

	     for(int i=0;i<(NumberOfPoints-1);i++)
         {
             z=poly[i].compare(poly[i+1]);
            if(z==1)
             {
                 for(int k=i;k<(NumberOfPoints-1);k++)
                 {
                     setpoint(poly[k+1],k);
                 }
                 count ++;
                 NumberOfPoints--;
                 i--;
             }
         }


         for(int q=0;q<(NumberOfPoints-2);q++)
         {
             m=poly[q+2].slope(poly[q+1]);
             n=poly[q+1].slope(poly[q]);
              if(n==m)
             {
                 for(int o=(q+1);o<(NumberOfPoints-1);o++)
                 {
                     setpoint(poly[o+1],o);
                 }
                 count ++;
                 NumberOfPoints--;
                 q--;
             }
         }
         z = poly[0].compare(poly[(NumberOfPoints-1)]);
	     if(z==1)
         {
              count++;
              poly[NumberOfPoints-1].setx(0);
              poly[NumberOfPoints-1].sety(0);
              NumberOfPoints--;
         }
         m = poly[0].slope(poly[(NumberOfPoints-1)]);
         n = poly[(NumberOfPoints-1)].slope(poly[(NumberOfPoints-2)]);
         if(n==m)
             {
              count++;
              poly[NumberOfPoints-1].setx(0);
              poly[NumberOfPoints-1].sety(0);
              NumberOfPoints--;
             }
         m = poly[1].slope(poly[0]);
         n = poly[0].slope(poly[(NumberOfPoints-1)]);
         if(n==m)
             {
               for(int a=0;a<(NumberOfPoints-1);a++)
                 {
                     setpoint(poly[a+1],a);
                 }
                  count++;
              NumberOfPoints--;
             }
             return count;
         }

         int serch (point p)
         {
            for(int i=0;i<reaal;i++)
            {
                int z=0;
                z=p.compare(poly_before_redundant[i]);
                if(z==1)
                {
                    return 1;
                }
            }
            return 0;
         }
         float perimeter ()
         {
             float perimeter=0;
              int n=NumberOfPoints;
	          for(int i=0;i<n;i++)
              {
                  if(i==(n-1))
                  {
                      float x=poly[i].distance(poly[0]);
                       perimeter+=x;
                  }
                  else
                    {
                   float x=poly[i].distance(poly[i+1]);
                  perimeter+=x;
                    }
              }
              return perimeter;
         }
         int is_rectangular()
         {
             if(NumberOfPoints==4)
             {
                 float m1=poly[0].distance(poly[1]);
                 float n1=poly[1].distance(poly[2]);
                 float m2=poly[2].distance(poly[3]);
                 float n2=poly[3].distance(poly[0]);
                 if((m1==m2)&&(n1==n2))
                 {
                         float x1=poly[0].slope(poly[1]);
                         float y1=poly[1].slope(poly[2]);
                         float x2=poly[2].slope(poly[3]);
                         float y2=poly[0].slope(poly[3]);
                         if(((fabs(x1))==(fabs(x2)))&&((fabs(y1))==(fabs(y2))))
                         {
                             float a=poly[0].distance(poly[2]);
                             float b=poly[1].distance(poly[3]);
                             if(a==b)
                             {
                                 return 1;
                             }
                         }

                 }
             }
             return 0;
         }
         int is_trapzoid()
         {
             if(NumberOfPoints==4)
             {
                 float m1=poly[0].distance(poly[1]);
                 float n1=poly[1].distance(poly[2]);
                 float m2=poly[2].distance(poly[3]);
                 float n2=poly[3].distance(poly[0]);
                 float x1=fabs(poly[0].slope(poly[1]));
                 float y1=fabs(poly[1].slope(poly[2]));
                 float x2=fabs(poly[2].slope(poly[3]));
                 float y2=fabs(poly[0].slope(poly[3]));
                 if((x1==x2)&&(m1!=m2))
                 {
                     return 1;
                 }
                 if((y1==y2)&&(n1!=n2))
                 {
                     return 1;
                 }

         }
         return 0;
         }
         float max_x()
         {
             float max_x=poly[0].getx();
             for(int i=1;i<NumberOfPoints;i++)
                {
                float a=poly[i].getx();
                if(a>max_x)
             {
                 max_x=a;
             }
                }
                return max_x;
         }
          float max_y()
         {
             float max_y=poly[0].gety();
             for(int i=1;i<NumberOfPoints;i++)
                {
                float a=poly[i].gety();
                if(a>max_y)
             {
                 max_y=a;
             }
                }
                return max_y;
         }
         float min_y()
         {
             float min_y=poly[0].gety();
             for(int i=1;i<NumberOfPoints;i++)
                {
                float a=poly[i].gety();
                if(a<min_y)
             {
                 min_y=a;
             }
                }
                return min_y;
         }
          float mnx()
         {
             float mnx=poly[0].getx();
             for(int i=1;i<NumberOfPoints;i++)
                {
                float ab=poly[i].getx();
                if(ab<mnx)
             {
                 mnx=ab;
             }
                }
                return mnx;
         }
         int is_inside_rec(point a1,point a2,point a3,point a4,float a[],float b[])
         {
           point p=midpoint(a1,a3);
          float x=a1.gety(),y=a2.gety();
          float x2=a1.getx(),y2=a2.getx();
          if((x==y)||(x2==y2))
          {
              float xH=MAX(a,4);
              float yH=MAX(b,4);
              float xL=MIN(a,4);
              float yL=MIN(b,4);
              if(xH>max_x()||xH==max_x())
            {
                  if(yH>max_y()||yH==max_y())
                 {
                  if(yL<min_y()||yL==min_y())
                  {
                     if(xL<mnx()||xL==mnx())
                        {
                  return 1;
                        }
                  }
                 }
              }
          }
          else
            {
            float h=a1.distance(a2);
            float w=a2.distance(a3);
            for(int i=0;i<NumberOfPoints;i++)
            {
            float o=poly[i].distance_from_line(a1,a2)+poly[i].distance_from_line(a3,a4);
            float p=poly[i].distance_from_line(a2,a3)+poly[i].distance_from_line(a4,a1);

            float oo,ww,pp,hh;
            ww=roundf(w*100)/100;
            oo=roundf(o*100)/100;
            hh=roundf(h*100)/100;
            pp=roundf(p*100)/100;
            if( ww == oo )
            {
                if(pp==hh)
                {
                continue;
                }
            }
            return 0;
            }
            return 1;
            }
         }
          int is_inside_cir(point p , float r)
          {
              for(int i=0;i<NumberOfPoints;i++)
              {
                  float d=poly[i].distance(p);
                  if(d>r)
                  {
                      return 0;
                  }
              }
              return 1;
          }
         float  area ()
         {
             float x=0,y=0;
    for(int i=0;i<(NumberOfPoints);i++)
                 {
                     if(i==(NumberOfPoints-1))
                     {
                           float temp=poly[i].getx()*poly[0].gety();
                           x=x+temp;
                           break;
                     }
                    float temp=poly[i].getx()*poly[i+1].gety();
                    x=x+temp;
                 }
    for(int i=0;i<(NumberOfPoints);i++)
                 {
                     if(i==(NumberOfPoints-1))
                     {
                           float temp=poly[i].gety()*poly[0].getx();
                           y=y+temp;
                           break;
                     }
                    float temp=poly[i].gety()*poly[i+1].getx();
                    y=y+temp;

                 }
                 float area=x-y;
                 area =fabs( area/2);
                 return area;
         }
         int is_inside_point(point p)
         {
             int counter=0;
             float a=p.getx();
             float b=p.gety();
             if(a<mnx()||a>max_x()||b>max_y()||b<min_y())
             {
                 return 0;
             }
             for(int h=0;h<NumberOfPoints;h++)
             {
                 int d=h;
                 int t=d+1;
                 if(d==(NumberOfPoints-1))
                 {
                     t=0;
                 }
                 if(p.compare(poly[t])||p.compare(poly[d]))
                 {
                     return 1;
                 }
                 float b1=poly[d].gety();
                 float b2=poly[t].gety();
                  float a1=poly[d].getx();
                 float a2=poly[t].getx();
                if(a1 == a2)
                 {
                     if(a==a1)
                     {
                         if((b>b1)&&(b<b2)||(b>b2)&&(b<b1))
                         {
                             return 1;
                         }
                         else{return 0;}
                     }
                if(((b1<b)&&(b2>b))||((b1>b)&&(b2<b)))
                     {
                  if(poly[d].getx()>a)
                 {
                     counter++;
                 }
                 continue;
                      }
                 }
                 int k=is_on_line(p,poly[d],poly[t]);
                 if(k==1)
                 {
                     return 1;
                 }
                 if(b==b2||b==b1)
                 {
                     b=b+.00001;
                 }
                  if(((b1<b)&&(b2>b))||((b1>b)&&(b2<b)))
                 {
                float m=poly[d].slope(poly[t]);
                 float c=poly[d].gety()-m*poly[d].getx();
                 float comp=(b-c)/m;
                 if(comp>a)
                 {
                     counter++;
                 }
                 }
             }
             if(counter==0)
             {
                 return 0;
             }
             if((counter%2)==0)
             {
                 return 0;
             }
             return 1;
         }
        int intersecting (polygon P)
         {
          for(int w=0;w<NumberOfPoints;w++)
          {
              int b=w;
              int e=b+1;
              if(b==(NumberOfPoints-1))
              {
                  e=0;
              }
              int rounds=P.NumberOfPoints;
              for(int v=0;v<rounds;v++)
              {
                  int bb=v;
                  int ee=bb+1;
                  if(bb==(rounds-1))
              {
                  ee=0;
              }
                  int k=two_line_intersect(poly[b],poly[e],P.poly[bb],P.poly[ee]);
                  if(k==1)
                  {
                      return 1;
                  }
              }
          }
          return 0;
         }
        float intersecting_area(polygon P)
        {
            int c=0;
            polygon AREA;
            int startFirstP,endFirstP,startSecondP,endSecondP;
            for(int i=0;i<NumberOfPoints;i++)
            {
                startFirstP=i;
                endFirstP=startFirstP+1;
                if (endFirstP==NumberOfPoints)
                {
                    endFirstP=0;
                }
                int rounds=P.getNO_Points();
                for(int j=0;j<rounds;j++)
                {
                startSecondP=j;
                endSecondP=startSecondP+1;
                 if (endSecondP==rounds)
                {
                    endSecondP=0;
                }
                int k=two_line_intersect(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                  if(k==1)
                  {
                   point p=two_line_intersect_point(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                   AREA.setpoint(p,c);
                   c++;
                  int yy=P.is_inside_point(poly[endFirstP]);
                  int yyy=P.is_inside_point(poly[startFirstP]);
                  if(yy==1)
                       {
                                AREA.setpoint(poly[endFirstP],c);
                                c++;
                       }
                       if(yyy==1)
                       {
                                AREA.setpoint(poly[startFirstP],c);
                                c++;
                                yy=1;
                       }
                  if(yy==0)
                                 {
                                          for(int j=endSecondP;j<rounds;j++)
                                                {
                                                 startSecondP=j;
                                                 endSecondP=startSecondP+1;
                                                 if (endSecondP==rounds)
                                                         {
                                                          endSecondP=0;
                                                         }
                                                 int k=two_line_intersect(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                                                 if(k==1)
                                                 {
                                                 point p=two_line_intersect_point(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                                                 AREA.setpoint(p,c);
                                                 c++;
                                                 break;
                                                 }
                                                }
                                 }
                                                    for(int i=endFirstP;i<NumberOfPoints;i++)
                                                       {
                                                        startFirstP=i;
                                                        endFirstP=startFirstP+1;
                                                        if(startFirstP==(NumberOfPoints-1))
                                                        {
                                                        endFirstP=0;
                                                        }
                                                        int rounds=P.NumberOfPoints;
                                                        for(int j=0;j<rounds;j++)
                                                        {
                                                        int startSecondP=j;
                                                        int endSecondP=startSecondP+1;
                                                        if(startSecondP==(rounds-1))
                                                        {
                                                        endSecondP=0;
                                                        }
                                                        int k=two_line_intersect(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                                                        if(k==1)
                                                        {
                                                        point p=two_line_intersect_point(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                                                        AREA.setpoint(p,c);
                                                        c++;
                                                        int o=is_inside_point(P.poly[startSecondP]);
                                                        if(o==1)
                                                        {
                                                          AREA.setpoint(P.poly[startSecondP],c);
                                                          c++;
                                                        }
                                                        else
                                                            {
                                                            int oo=is_inside_point(P.poly[endSecondP]);
                                                            if(oo==1)
                                                                {
                                                                   AREA.setpoint(P.poly[endSecondP],c);
                                                                   c++;
                                                                }
                                                            else
                                                                {
                                                                for(int w=endSecondP;w<rounds;w++)
                                                                      {
                                                                           startSecondP=w;
                                                                            endSecondP=startSecondP+1;
                                                                            if (endSecondP==rounds)
                                                                             {
                                                                              endSecondP=0;
                                                                             }
                                                                             int k=two_line_intersect(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                                                                             if(k==1)
                                                                            {
                                                                             point p=two_line_intersect_point(poly[startFirstP],poly[endFirstP],P.poly[startSecondP],P.poly[endSecondP]);
                                                                             AREA.setpoint(p,c);
                                                                            c++;
                                                                            }

                                                                      }

                                                            }
                                                        }
                                                        AREA.setNO_Points(c);
                                                       AREA.redun();
                                                       return AREA.area();

                                                        }
                                                        }
                                                        }



                  }
                }
            }
        }
 };

void horiz_axis(string s , float x[]);
void vertical_axis(string s,float y[]);
void set_number_and_points(string s, polygon x []);
int NumberOfPolygons(string s);
void set_points_in_each_poly(int number ,polygon[],int n, float x[],float y[]);
int   NumberOfPoints(string s);
float MAX (float v[],int n);
float MIN(float v[],int n);
 point midpoint(point a,point b);
int is_connected(int a,int b,int number,polygon poly[]);

 int main()
 {

 string s;
 getline(cin,s);
 int number=NumberOfPolygons(s);
 int  n= NumberOfPoints(s);
    float x[10000];
     horiz_axis (s,x);     //function to get array of x values
	 float y[10000];
	 vertical_axis(s,y);    //function to get array of y values
     polygon poly[100];
     set_number_and_points(s,poly);//put number of each polygon and it's points number
    set_points_in_each_poly(number,poly,n,x,y);//set points in each point
     float maxX=MAX(x,n),maxY=MAX(y,n),minX=MIN(x,n),minY=MIN(y,n);
     for(int yy=0;yy<number;yy++)
            {
                poly[yy].setpoly_before_redundant();
                poly[yy].setreaal(poly[yy].getNO_Points());
            }
            int sum=0;
            for(int i=0;i<number;i++)
            {
                sum+=poly[i].redun();
            }
    string operation;
    while(1)
      {
          getline(cin,operation);
           string q=operation.substr(0,14);
           string str=operation.substr(0,25);
           string str1=operation.substr(0,26);
           string str2=operation.substr(0,17);
           string str3=operation.substr(0,16);
           string str4=operation.substr(0,13);
           string str5=operation.substr(0,12);
            string str6=operation.substr(0,19);
           string str7=operation.substr(0,24);
           string str8=operation.substr(0,15);
           string str9=operation.substr(0,18);
           string str10=operation.substr(0,12);
           cout<<endl;
    if(operation=="Number_Polygons")
        cout<<number;cout<<endl;
    if(operation=="Total_Number_Points")
        cout<<endl<<n<<endl;
    if(operation=="Minimum_X")
        cout<<minX<<endl;
    if(operation=="Maximum_X")
         cout<<maxX<<endl;
    if(operation=="Minimum_Y")
        cout<< minY<<endl;
    if(operation=="Maximum_Y")
        cout<<maxY<<endl;
    if(operation=="Enclosing_Rectangle")
        cout<<"[("<<minX<<","<<maxY<<"),("<<maxX<<","<<maxY<<"),("<<maxX<<","<<minY<<"),("<<minX<<","<<minY<<")]"<<endl;
    if(operation=="Quit")
        exit(0);
    if(operation=="Total_Redundant_Points")
        {
            if(sum==0){cout<<"none";continue;}
            cout<<sum;cout<<endl;
        }
      if(q=="Polygon_Points")
      {
          int ww=operation.length();
          string we=operation.substr(14,ww-14);
          int nn=atof(we.c_str());
          poly[nn-1].print();
          cout<<endl;
      }
       if(q=="Point_Polygons")
       {
           point p;
        int pp=operation.length();
        for(int r=14;r<pp;r++)
        {
            if (operation[r]=='(')
            {
                for(int o=r;o<pp;o++)
                {
                    if(operation[o]==',')
                    {

            string xe=operation.substr(r+1,o-r-1);
          float xx=atof(xe.c_str());
          p.setx(xx);
          break;
                    }
                }
             r++;
            }
            if (operation[r]==',')
            {
                for(int u=r;u<pp;u++)
                {
                    if(operation[u]==')')
                    {

            string ye=operation.substr(r+1,u-r-1);
          float yata=atof(ye.c_str());
          p.sety(yata);
          break;
                    }
                }
             r+=2;
            }
        }
int c=0;
for(int i=0;i<number;i++)
{
    int k=0;
    k=poly[i].serch(p);
    if(k==1)
    {
        if(c==0)
        {
            cout<<poly[i].getPolyNum();
            c++;
        }
        else
        {
            cout<<",";
            cout<<poly[i].getPolyNum();
        }
    }
}if(c==0){cout<<"none";}cout<<endl;
       }

        if(str=="List_Polygons_Points More")
        {
          int nn=operation.length();
          string hi=operation.substr(25,nn-25);
          int bb=atof(hi.c_str());
          int tt=0;
          for(int rr=0;rr<number;rr++)
          {
              int temp=poly[rr].getNO_Points();
              if(temp>bb)
              {
                if(tt==0)
        {
            cout<<poly[rr].getPolyNum();
        tt++;
        }
        else
        {
            cout<<",";
            cout<<poly[rr].getPolyNum();
        }
              }
          }
          if(tt==0){cout<<"none";}cout<<endl;
          }
      if(str=="List_Polygons_Points Less")
        {
          int mm=operation.length();
          string hii=operation.substr(25,mm-25);
        int num=atof(hii.c_str());
          int ttt=0;
          for(int rrr=0;rrr<number;rrr++)
          {
              int temp=poly[rrr].getNO_Points();
              if(temp<num)
              {
                if(ttt==0)
        {
            cout<<poly[rrr].getPolyNum();
        ttt++;
        }
        else
        {
            cout<<",";
            cout<<poly[rrr].getPolyNum();
        }
              }
          }if(ttt==0){cout<<"none";}cout<<endl;

      }
      if(str1=="List_Polygons_Points Equal")
        {
          int l=operation.length();
          string hhh=operation.substr(26,l-26);
          int bbbb=atof(hhh.c_str());
          int yay=0;
          for(int ll=0;ll<number;ll++)
          {
              int temp=poly[ll].getNO_Points();
              if(temp==bbbb)
              {
                if(yay==0)
        {
            cout<<poly[ll].getPolyNum();
        yay++;
        }
        else
        {
            cout<<",";
            cout<<poly[ll].getPolyNum();
        }
              }
          }if(yay==0){cout<<"none";}
          cout<<endl;
          }
      if(str=="List_Points_Polygons More")
        {
          int numberofchars=operation.length();
          string hello=operation.substr(25,numberofchars-25);
          int refrence=atof(hello.c_str());
          int c=0;
          point pplo [100];
          for(int i=0;i<number;i++)
            {
                int times=poly[i].getreaal();
                for(int k=0;k<times;k++)
                   {
                       int sum=0;
                      point p=poly[i].getpointbefore_redundant(k);
                      for(int u=0;u<number;u++)
                      {
                          int yes=poly[u].serch(p);
                          sum=sum+yes;
                      }

                      if (sum>refrence)
                      {
                          if(c==0)
                          {
                             pplo[c].equalpoint(p);
                             c++;
                          }
                          else
                           {
                               int checker=1;
                            for(int t=0;t<c;t++)
                            {
                                int bb=p.compare(pplo[t]);
                                if(bb==1)
                                {
                                    checker=0;
                                    break;
                                }
                            }
                            if(checker==1)
                            {
                              pplo[c].equalpoint(p);
                              c++;
                            }
                           }
                      }

            }
            }if(c==0)
            {
                cout<<"none";
            }
             for(int eee=0;eee<c;eee++)
            {
                if(eee==0)
                {pplo[eee].print();}
                else
                {
                        cout<<",";
                pplo[eee].print();
                }

            }
            cout<<endl;
        }
      if(str=="List_Points_Polygons Less")
        {
          int numberofchars=operation.length();
          string hello=operation.substr(25,numberofchars-25);
          int refrence=atof(hello.c_str());
          int c=0;
          point pplo [100];
          for(int i=0;i<number;i++)
            {
                int times=poly[i].getreaal();
                for(int k=0;k<times;k++)
                   {
                       int sum=0;
                      point p=poly[i].getpointbefore_redundant(k);
                      for(int u=0;u<number;u++)
                      {
                          int yes=poly[u].serch(p);
                          sum=sum+yes;
                      }

                      if (sum<refrence)
                      {
                          if(c==0)
                          {
                             pplo[c].equalpoint(p);
                             c++;
                          }
                          else
                           {
                               int checker=1;
                            for(int t=0;t<c;t++)
                            {
                                int bb=p.compare(pplo[t]);
                                if(bb==1)
                                {
                                    checker=0;
                                    break;
                                }
                            }
                            if(checker==1)
                            {
                              pplo[c].equalpoint(p);
                              c++;
                            }
                           }
                      }

            }
            }if(c==0)
            {
                cout<<"none";
            }
             for(int eee=0;eee<c;eee++)
            {
                if(eee==0)
                {pplo[eee].print();}
                else
                {
                        cout<<",";
                pplo[eee].print();
                }

            }
            cout<<endl;
        }
      if(str1=="List_Points_Polygons Equal")
        {
          int numberofchars=operation.length();
          string hello=operation.substr(26,numberofchars-26);
          int refrence=atof(hello.c_str());
          int c=0;
          point pplo [100];
          for(int i=0;i<number;i++)
            {
                int times=poly[i].getreaal();
                for(int k=0;k<times;k++)
                   {
                       int sum=0;
                      point p=poly[i].getpointbefore_redundant(k);
                      for(int u=0;u<number;u++)
                      {
                          int yes=poly[u].serch(p);
                          sum=sum+yes;
                      }

                      if (sum==refrence)
                      {
                          if(c==0)
                          {
                             pplo[c].equalpoint(p);
                             c++;
                          }
                          else
                           {
                               int checker=1;
                            for(int t=0;t<c;t++)
                            {
                                int bb=p.compare(pplo[t]);
                                if(bb==1)
                                {
                                    checker=0;
                                    break;
                                }
                            }
                            if(checker==1)
                            {
                              pplo[c].equalpoint(p);
                              c++;
                            }
                           }
                      }

            }
            }if(c==0)
            {
                cout<<"none";
            }
             for(int eee=0;eee<c;eee++)
            {
                if(eee==0)
                {pplo[eee].print();}
                else
                {
                        cout<<",";
                pplo[eee].print();
                }
            }
            cout<<endl;
        }
      if(str2=="Polygon_Perimeter")
        {
          int numberofchars=operation.length();
          string hello=operation.substr(17,numberofchars-17);
          int polynumm=atof(hello.c_str());
        cout<<poly[(polynumm-1)].perimeter()<<endl;
        }
      if(operation=="List_Triangles")
      {
       int c=0;
       for(int i=0;i<number;i++)
       {
           int num=poly[i].getNO_Points();
           if(num==3)
           {
               if(c==0)
               {
                   cout<<poly[i].getPolyNum();
                   c++;
               }
               else
                {
                   cout<<","<<poly[i].getPolyNum();
                   c++;
                }
           }
       }
       if(c==0)
       {
           cout<<"none"<<endl;
       }
       cout<<endl;
      }
      if(operation=="List_Rectangles")
      {
        int c=0;
        for(int i=0;i<number;i++)
        {
            int k=0;
            k=poly[i].is_rectangular();
            if(k==1)
            {
                if(c==0)
                {
                    cout<<poly[i].getPolyNum();
                    c++;
                }
                else
                    {
                    cout<<",";
                cout<<poly[i].getPolyNum();
                c++;
                    }
            }
        }
        if(c==0)
            {
                cout<<"none";
            }
            cout<<endl;
      }
      if(operation=="List_Trapezoid")
      {
        int c=0;
        for(int i=0;i<number;i++)
        {
            int k=0;
            k=poly[i].is_trapzoid();
            if(k==1)
            {
                if(c==0)
                {
                    cout<<poly[i].getPolyNum();
                    c++;
                }
                else
                    {
                    cout<<",";
                cout<<poly[i].getPolyNum();
                c++;
                    }
            }
        }
        if(c==0)
            {
                cout<<"none";
            }
            cout<<endl;
      }
      if(str3=="Inside_Rectangle")
      {
         int n=operation.length();
         string hii=operation.substr(16,n-16);
        float a[4];float b[4];
        vertical_axis( hii,b);
        horiz_axis(hii,a);int c=0;
        point a1,a2,a3,a4;
        a1.setx(a[0]);a1.sety(b[0]);
        a2.setx(a[1]);a2.sety(b[1]);
        a3.setx(a[2]);a3.sety(b[2]);
        a4.setx(a[3]);a4.sety(b[3]);
        for (int i=0;i<number;i++)
        {
            int k=poly[i].is_inside_rec(a1,a2,a3,a4,a,b);
            if (k==1)
            {
                 if(c==0)
        {
            cout<<poly[i].getPolyNum();
        c++;
        }
        else
        {
            cout<<",";
            cout<<poly[i].getPolyNum();
        }
              }
          }
          if(c==0){cout<<"none";}cout<<endl;
            }
      if(str4=="Inside_Circle")
       {
           point p; float radius;
        int pp=operation.length();
        for(int r=13;r<pp;r++)
        {
            if (operation[r]=='(')
            {
                for(int o=r;o<pp;o++)
                {
                    if(operation[o]==',')
                    {

            string xe=operation.substr(r+1,o-r-1);
          float xx=atof(xe.c_str());
          p.setx(xx);
          break;
                    }
                }
             r++;
            }
            if (operation[r]==',')
            {
                for(int u=r;u<pp;u++)
                {
                    if(operation[u]==')')
                    {

            string ye=operation.substr(r+1,u-r-1);
          float yata=atof(ye.c_str());
          p.sety(yata);
          string yee=operation.substr(u+2);
          float yataa=atof(yee.c_str());
          radius=yataa;
          break;
                    }
                }
             break;
            }
        }
          int c=0;
          for(int i=0;i<number;i++)
          {
              int k=poly[i].is_inside_cir(p,radius);
               if (k==1)
            {
                 if(c==0)
        {
            cout<<poly[i].getPolyNum();
        c++;
        }
        else
        {
            cout<<",";
            cout<<poly[i].getPolyNum();
        }
              }
          }
          if(c==0){cout<<"none";}cout<<endl;
          }
      if(str5=="Polygon_Area")
      {
          int numberofchars=operation.length();
          string hello=operation.substr(12,numberofchars-12);
          int polynumm=atof(hello.c_str());
          float A=poly[polynumm-1].area();
          cout<<A<<endl;
      }
      if(str6=="Polygons_Area_Range")
      {
          int n=operation.length();
          int t=operation.find(',');
            string hello=operation.substr(19,t-19);
            float minArea=atof(hello.c_str());
            string hello1=operation.substr(t+1);
            float maxArea=atof(hello1.c_str());
          int c=0;
          for(int i=0;i<number;i++)
          {
              float area=poly[i].area();
              if(area<maxArea||area==maxArea)
              {
                  if(area>minArea||area==minArea)
                  {
                       if(c==0)
                {
                    cout<<poly[i].getPolyNum();
                    c++;
                }
                else
                    {
                    cout<<",";
                cout<<poly[i].getPolyNum();
                c++;
                    }
                  }
              }

          }
          if(c==0)
            {
                cout<<"none";
            }

      }
       if(str7=="Polygons_Enclosing_Point")
       {
         point p;
        int pp=operation.length();
        int c=0;
        for(int r=24;r<pp;r++)
        {
            if (operation[r]=='(')
            {
                for(int o=r;o<pp;o++)
                {
                    if(operation[o]==',')
                    {

            string xe=operation.substr(r+1,o-r-1);
          float xx=atof(xe.c_str());
          p.setx(xx);
          break;
                    }
                }
             r++;
            }
            if (operation[r]==',')
            {
                for(int u=r;u<pp;u++)
                {
                    if(operation[u]==')')
                    {

            string ye=operation.substr(r+1,u-r-1);
          float yata=atof(ye.c_str());
          p.sety(yata);
          break;
                    }
                }
             r+=2;
            }
        }
        for(int i=0;i<number;i++)
          {
    int k=poly[i].is_inside_point(p);
    if(k==1)
            {
                if(c==0)
                {
                    cout<<poly[i].getPolyNum();
                    c++;
                }
                else
                    {
                    cout<<",";
                cout<<poly[i].getPolyNum();
                c++;
                    }
            }
        }
        if(c==0)
            {
                cout<<"none";
            }
            cout<<endl;
          }
      if(str8=="Is_Intersecting")
      {
         int n=operation.length();
          int t=operation.find(',');
            string hello=operation.substr(15,t-15);
            int first=atof(hello.c_str());
            string hello1=operation.substr(t+1);
            int second=atof(hello1.c_str());
            int k = poly[first-1].intersecting(poly[second-1]);
            if (k==1)
            {
                cout<<"TRUE"<<endl;
            }
            else
                {
                cout<<"FALSE"<<endl;
                }
      }
      if(str9=="Intersecting_Group")
      {
          int c=0;
          int r=18;
          int n=operation.length();
          int a [100];
          for(int i=19;i<n;i++)
          {
              if(i==(n-1))
              {
            string hello=operation.substr(r+1);
            int numberin=atof(hello.c_str());
            a[c]=numberin;
            c++;
            break;
              }
            if(operation[i]==',')
          {
            string hello=operation.substr(r+1,i-1-r);
            int numberin=atof(hello.c_str());
            a[c]=numberin;
            r=i;
            c++;
          }
          }
          for(int j=0;j<c;j++)
          {
              for(int u=(j+1);u<c;u++)
              {
                  int k=poly[a[j]-1].intersecting(poly[a[u]-1]);
                  if(k==0)
                  {
                      r=0;
                  }
              }
          }
          if(r==0)
          {
              cout<<"FALSE"<<endl;
              continue;
          }
          cout<<"TRUE"<<endl;
      }
       if (operation=="Largest_Intersecting_Pair")
       {
           float area[100];
           int c=0;float maxx;
           int a=0;
           int b=0;
           for(int u=0;u<number;u++)
           {
               int e=u;
               for(int r=(e+1);r<number;r++)
               {
                   int j=r;
                   int k=poly[e].intersecting(poly[j]);
                   if(k==1)
                   {
                       area[c]=poly[e].intersecting_area(poly[j]);
                     if (c==0)
                     {
                         maxx=area[0];
                         a = (e+1);
                         b = (j+1);
                     }
                     else if(area[c]>maxx)
                     {
                           maxx=area[c];
                           a = (1+e);
                            b = (1+j);
                     }
                     c++;
                   }
               }
           }
           cout<<a<<","<<b;
       }
       if(str10=="Is_Connected"&&(operation[12]!='_'))
        {
            int n=operation.length();
          int t=operation.find(',');
            string hello=operation.substr(12,t-12);
            int first=atof(hello.c_str());
            string hello1=operation.substr(t+1);
            int second=atof(hello1.c_str());
            first--;
            second--;
            int k=is_connected(first,second,number,poly);
           if (k==1)
            {
                cout<<"TRUE"<<endl;
            }
            else
                {
                cout<<"FALSE"<<endl;
                }
         }
       if(str9=="Is_Connected_Group")
       {
           int c=0;
          int r=18;
          int n=operation.length();
          int a [100];
          for(int i=19;i<n;i++)
          {
              if(i==(n-1))
              {
            string hello=operation.substr(r+1);
            int numberin=atof(hello.c_str());
            a[c]=numberin;
            c++;
            break;
              }
            if(operation[i]==',')
          {
            string hello=operation.substr(r+1,i-1-r);
            int numberin=atof(hello.c_str());
            a[c]=numberin;
            r=i;
            c++;
          }
          }
          for(int j=0;j<c;j++)
          {
              for(int u=(j+1);u<c;u++)
              {
                  int k=is_connected(a[j]-1,a[u]-1,number,poly);
                  if(k==0)
                  {
                      r=0;
                  }
              }
          }
          if(r==0)
          {
              cout<<"FALSE"<<endl;
              continue;
          }
          cout<<"TRUE"<<endl;
      }
       if(operation=="Maximum_Intersecting_Group")
       {
           int oop=0;
           int aho;
           int v[100];
           for(int i=0;i<number;i++)
           {
               int retry[100];
               int counter=0;
               for(int j=0;j<number;j++)
               {
                   if(i==j)
                   {
                       continue;
                   }
                 int k = poly[i].intersecting(poly[j]);
                 for(int oop=0;oop<counter;oop++)
                 {
                  int k = poly[j].intersecting(poly[retry[counter]]);
                  if(k==0)
                  {
                      counter--;
                  }
                 }
                 retry[counter]=j;
                 if (k==1)
                 {
                counter++;
                 }
               }
               v[i]=counter;
           }
           int maxx;int r;
           for(int i=0;i<number;i++)
           {
               if(i==0)
               {
                   maxx=v[0];
                   r=0;
               }
               if(v[i]>maxx)
               {
                   maxx=v[i];
                   r=i;
               }
           }
           cout<<(r+1);
           oop=0;
           int yyy[100];
           for(int i=0;i<number;i++)
           {
               if(i==r)
               {
                   continue;
               }
                int k = poly[r].intersecting(poly[i]);
            if (k==1)
            {
              yyy[oop]=i;
              oop++;
            }
           }
           int iii[100];
           for(int z=0;z<oop;z++)
           {
               int checkk=0;
               for(int o=0;o<oop;o++)
               {
                   if(o!=z)
                   {
                        int k = poly[yyy[o]].intersecting(poly[yyy[z]]);
                        if (k==1)
                        {
                            checkk++;
                        }
                   }
               }
               iii[z]=checkk;
           }
           maxx=0;
           for(int l=0;l<oop;l++)
           {
               if (l==0)
                {
                    maxx==iii[0];
                }
               if(iii[l]>maxx)
               {
                   maxx==iii[l];
                   aho=l;
               }
           }
            cout<<","<<(yyy[aho]+1);
           for(int z=0;z<oop;z++)
           {
                        if(z!=aho)
                        {
                        int k = poly[yyy[aho]].intersecting(poly[yyy[z]]);
                        if (k==1)
                        {
                            cout<<","<<(yyy[z]+1);
                        }
       }}
       }
       if(operation=="Maximum_Connected_Group")
       {
           int v[100];
           for(int i=0;i<number;i++)
           {
               int counter=0;
               for(int j=0;j<number;j++)
               {
                   if(i==j)
                   {
                       continue;
                   }
                 int k =is_connected(i,j,number,poly);
                 if (k==1)
                 {
                counter++;
                 }
               }
               v[i]=counter;
           }
           int maxx;int r;
           for(int i=0;i<number;i++)
           {
               if(i==0)
               {
                   maxx=v[0];
                   r=0;
               }
               if(v[i]>maxx)
               {
                   maxx=v[i];
                   r=i;
               }
           }
           cout<<(r+1);
           for(int i=0;i<number;i++)
           {
               if(i==r)
               {
                   continue;
               }
             int k =is_connected(r,i,number,poly);
            if (k==1)
            {
              cout<<","<<(i+1);
            }
           }
       }
       }
       }
int is_connected(int a,int b,int number,polygon poly[])
{
    int orb[100];
    int c=0;int h=1;
            for(int i=0;i<number;i++)
            {
                if(a==i)
                {
                    continue;
                }
                int k = poly[a].intersecting(poly[i]);
                if(k==1)
                {
                     if(i==b)
                         {
                             return 1;
                         }
                   orb[c]=i;
                   c++;
                }
            }
            int w=0;
            for(int j=0;j<c;j++)
            {
                for(int i=0;i<number;i++)
                {
                    if(orb[j]==i)
                    {
                        continue;
                    }
                     int k = poly[orb[j]].intersecting(poly[i]);
                     if(k==1)
                     {
                         if(i==a)
                         {
                             continue;
                         }
                         if(i==b)
                         {
                             return 1;
                         }
                         for(int r=0;r<c;r++)
                         {
                             if(orb[r]==i)
                                w=1;
                         }
                         if(w==0)
                         {
                             orb[c]=i;
                             c++;
                         }
                     }
                     w=1;
                }
            }
                        return 0;
}
point two_line_intersect_point(point a1,point b1,point a2,point b2)
       {
    float m1=a1.slope(b1);
    float m2=a2.slope(b2);
    if(a1.getx()==b1.getx())
    {
      float r=a1.getx();
        float c2=a2.gety()-m2*a2.getx();
        float   y33=m2*r+c2;
        point p;
        p.setx(r);p.sety(y33);
            return p;
    }
    if(a2.getx()==b2.getx())
    {
      float r=a2.getx();
        float c1=a1.gety()-m1*a1.getx();
        float     y33=m1*r+c1;
        point p;
        p.setx(r);p.sety(y33);
            return p;
    }

    float c1=a1.gety()-m1*a1.getx();
    float c2=a2.gety()-m2*a2.getx();
    float x=(c2-c1)/(m1-m2);
    float y1=m1*x+c1;
    point p;
    p.setx(x);
    p.sety(y1);
    return p;
       }
int two_line_intersect(point a1,point b1,point a2,point b2)
{
    float m1=a1.slope(b1);
    float m2=a2.slope(b2);
    if(m1==m2)
    {
        return 0;
    }
    if(a1.getx()==b1.getx())
    {
      float r=a1.getx();
        float c2=a2.gety()-m2*a2.getx();
        float   y33=m2*r+c2;
        point p;
        p.setx(r);p.sety(y33);
           float dis11=p.distance(a1)+p.distance(b1);
            float dis33=p.distance(a2)+p.distance(b2);
            float dis22=a1.distance(b1);
            float dis44=a2.distance(b2);
            float   dis1=roundf(dis11*100)/100;
            float dis2=roundf(dis22*100)/100;
             float dis3=roundf(dis33*100)/100;
            float dis4=roundf(dis44*100)/100;
            if((dis1==dis2)&&(dis3==dis4))
            {
                return 1;
            }
            return 0;
    }
    if(a2.getx()==b2.getx())
    {
      float r=a2.getx();
        float c1=a1.gety()-m1*a1.getx();
        float     y33=m1*r+c1;
        point p;
        p.setx(r);p.sety(y33);
           float dis11=p.distance(a1)+p.distance(b1);
            float dis33=p.distance(a2)+p.distance(b2);
            float dis22=a1.distance(b1);
            float dis44=a2.distance(b2);
            float dis1=roundf(dis11*1000)/1000;
            float dis2=roundf(dis22*1000)/1000;
             float dis3=roundf(dis33*1000)/1000;
            float dis4=roundf(dis44*1000)/1000;
            if((dis1==dis2)&&dis3==dis4)
            {
                return 1;
            }
            return 0;
    }
    float c1=a1.gety()-m1*a1.getx();
    float c2=a2.gety()-m2*a2.getx();
    float x=(c2-c1)/(m1-m2);
    float y1=m1*x+c1;
    float y2=m2*x+c2;
            point p;
            p.setx(x);p.sety(y1);
            float dis11=p.distance(a1)+p.distance(b1);
            float dis33=p.distance(a2)+p.distance(b2);
            float dis22=a1.distance(b1);
            float dis44=a2.distance(b2);
            float     dis1=roundf(dis11*1000)/1000;
            float dis2=roundf(dis22*1000)/1000;
             float dis3=roundf(dis33*1000)/1000;
            float dis4=roundf(dis44*1000)/1000;
            if((dis1==dis2)&&dis3==dis4)
            {
                return 1;
            }
            return 0;
}


int is_on_line(point a,point p1,point p2)
    {
        if(p1.gety()==p2.gety())
        {
            if(a.gety()==p1.gety())
            {
            float hi=p1.getx();
            float bye=p2.getx();
            float de=a.getx();
            if((hi>de)&&(bye<de)||(hi<de)&&(bye>de))
            {
                return 1;
            }
            return 0;
            }
        }
    float m=p1.slope(p2);
    float c=p1.gety()-m*p1.getx();
    float y=a.getx()*m+c;
    if(y==a.gety())
    {
        return 1;
    }
    return 0;
    }
 point midpoint(point a,point b)
         {
             float ax=a.getx();
             float ay=a.gety();
             float bx=b.getx();
             float by=b.gety();
             float q=(ax+bx)/2;
             float w=(ay+by)/2;
             point p;
             p.setx(q);p.sety(w);
             return p;
         }

 float MAX (float v[],int n)
{
    float mx=v[0];
    int i;
    for(i=1;i<n;i++)
    {
        if(v[i]>mx)
        {
           mx=v[i];
        }
    }
return mx;
}

float MIN(float v[],int n)
{
    float mn=v[0];
    int i;
    for(i=1;i<n;i++)
    {

        if(v[i]<mn)
    {
       mn=v[i];
    }
    }
return mn;
}
void set_points_in_each_poly(int number ,polygon poly [],int n, float x[],float y[])
{
    int i=0,k=0,o=0;
  for(i=0;i<number;i++)
     {
         int u= poly[i].getNO_Points();
         for(k=0;k<u;k++)
      {
                 point p;
                 p.setx(x[o]);
                 p.sety(y[o]);
                 poly[i].setpoint(p,k);
         o++;
      }
     }
}

 int NumberOfPoints(string s)
 {
 int n=s.length();
	 int i=0;
	 int c=0;
	 for(i=0;i<n;i++)
	 {
	 if (s[i]=='(')
	 {c=c+1;}
	 }
	 return c;
 }

 void set_number_and_points(string s, polygon x [])
{
  int n=s.length();

  int i=0,k=0,m=0;
  for(i=0;i<=n;i++)
  {
	 if (s[i]==';'||s[i]==']')
	 {
	     int p=0;
	 for(k;k<=i;k++)
	 {
	 if (s[k]=='(')
	 {
	     p=p+1;
	 }
	 }
	x[m].setPolyNum((m+1));
	x[m].setNO_Points(p);
	 m++;
	 }
  }
}

int NumberOfPolygons(string s)
 {
	 int n=s.length();
	 int i=0;
	 int c=1;
	 for(i=0;i<n;i++)
	 {
	 if (s[i]==';')
	 {c=c+1;}
	 }
	 return c;
 }

 void horiz_axis(string s , float x[])
{
    int n=s.length();
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            int i0=i;
            for(j=0;j<n;j++)
            {
             if(s[i0]==',')
             {
              break;
             }
             i0++;
            }
    string temp=s.substr(i+1,j-1);
    x[k]=atof(temp.c_str());
        k++;
        }
    }

}

 void vertical_axis(string s,float y[])
 {
    int n=s.length();
    int i=0,j,k=0;
    for(i=0;i<n;i++)
    {
        int i0=i;
        if(s[i0]==',')
        {
            if(s[i0+1]=='(')
                 continue;

            for(j=0;j<n;j++)
            {
             if(s[i0]==')')
             {
              break;
             }
             i0=i0+1;
            }
    string temp=s.substr(i+1,j-1);
        y[k]=atof(temp.c_str());
        k++;
        }
    }
 }
