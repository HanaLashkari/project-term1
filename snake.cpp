/*Hana Lashkari 402243094 github : HanaLashkari*/
#include <iostream>
#include "clui.h"
#include <time.h>
#include <stdlib.h>
using namespace std;
#define ziz 25

struct user{
    char name[11];
    int point , pt;
    int color , r , g , b;
    int x , y;
} u[ziz];
int helpful_i = 1 , n , m = helpful_i;

int num_speed , apple_x , apple_y , bomb_x , bomb_y;
bool gameover = false;
int gwc = 70 , gwr = 18;
int tail1_x[1000] , tail1_y[1000] , tail2_x[1000] , tail2_y[1000] , tail_num1 , tail_num2 ;
int t01 , t02;

void location()
{
    u[m].x = gwr/2 ;
    u[m].y = gwc-10 ;
    tail2_x[1] = gwr/2; tail2_y[1] = gwc-11;
    tail2_x[2] = gwr/2; tail2_y[2] = gwc-12;
    tail2_x[3] = gwr/2; tail2_y[3] = gwc-13;
    u[n].x = gwr/4 ;
    u[n].y = gwc-20 ;
    tail1_x[1] = gwr/4; tail1_y[1] = gwc-21;
    tail1_x[2] = gwr/4; tail1_y[2] = gwc-22;
    tail1_x[3] = gwr/4; tail1_y[3] = gwc-23;
    t01 = 's' ;
    t02 = 80;
    tail_num1 = 4;
    tail_num2 = 4;
}

int maximam(user u[] , int size)
{
    int max = 0;
    for(int i=0 ; i<=size ; i++)
        if(u[max].pt < u[i].pt)
            max = i;
    return max;
}

void bubble_sort(int  u1[] , int u2[] ,int size)
{
    for(int i=0 ; i<=size ; i++)
        for(int j=0 ; j<=size-1-i ; j++)
            if(u1[j] > u1[j+1])
            {
                int temp = u1[j];
                u1[j] = u1[j+1];
                u1[j+1] = temp;
                temp = u2[j];
                u2[j] = u2[j+1];
                u2[j+1] = temp;
            }
}

void scoreboard(){
    int u_help[ziz];
    int helpi[ziz];
    for(int i = 0 ; i<=helpful_i ; i++)
    {
        u_help[i] = u[i].pt;
        helpi[i] = i;
    }
    bubble_sort(u_help , helpi ,helpful_i);
    clear_screen();
    cursor_to_pos(get_window_rows()*2/5 , (get_window_cols()*3)/10);
    change_color_rgb(1,106,112);
    cout<<"-------------------------------------"<<endl;
    cursor_to_pos(get_window_rows()*2/5+1 , (get_window_cols()*3)/10);
    cout<<"|      ";
    change_color_rgb(210,222,50);
    cout<<"USERS";
    cursor_to_pos(get_window_rows()*2/5+1 , (get_window_cols()*3)/10+19);
    change_color_rgb(1,106,112);
    cout<<" |    ";
    change_color_rgb(210,222,50);
    cout<<"POINTS";
    cursor_to_pos(get_window_rows()*2/5+1 , (get_window_cols()*3)/10+34);
    change_color_rgb(1,106,112);
    cout<<"  |";
    cursor_to_pos(get_window_rows()*2/5+2 , (get_window_cols()*3)/10);
    cout<<"-------------------------------------"<<endl;
    for(int i=0 , j=1 , z=helpful_i ; z>=0 ; i += 2 , j++ , z--)
    {
        cursor_to_pos(get_window_rows()*2/5+i+3 , (get_window_cols()*3)/10);
        cout<<"| ";
        change_color_rgb(210,222,50);
        cout<<j<<")  "; 
        change_color_rgb(255,255,200);
        cout<<u[helpi[z]].name;
        cursor_to_pos(get_window_rows()*2/5+i+3 , (get_window_cols()*3)/10+19);
        cout<<" :    ";
        change_color_rgb(135,255,84);
        cout<<u_help[z];
        cursor_to_pos(get_window_rows()*2/5+i+3 , (get_window_cols()*3)/10+34);
        change_color_rgb(1,106,112);
        cout<<"  |"; 
        cursor_to_pos(get_window_rows()*2/5+i+4 , (get_window_cols()*3)/10);
        cout<<"-------------------------------------"<<endl;
    }

    cursor_to_pos(get_window_rows()*2/5+2*helpful_i+6 , (get_window_cols()*3)/10);
    change_color_rgb(255,255,200);
    cout<<"Click on \"esc\" to come back to menu.";
}

void random_bomb()
{
    srand(time(NULL));
    bomb_x = rand()%15+2;
    bomb_y = rand()%65+2;
    if(u[n].x == bomb_x && u[n].y == bomb_y)
        random_bomb();
    if(u[m].x == bomb_x && u[m].y == bomb_y)
        random_bomb();

}

void random_apple()
{
    srand(time(NULL));
    apple_x = rand()%14+3;
    apple_y = rand()%60+2;
    if(bomb_x == apple_x && bomb_y == apple_y)
        random_apple();
    if(u[n].x == apple_x && u[n].y == apple_y)
        random_apple();
    if(u[m].x == apple_x && u[m].y == apple_y)
        random_apple();
}

void change_speed()
{
    int gwc = get_window_cols() , gwr = get_window_rows();
    reset_color();
    cursor_to_pos((gwr*2)/5 , (gwc*2)/5);
    cout<<"Please choose your speed : ";
    change_color_rgb(35,230,15);
    cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5);
    cout<<"1) SLOW";
    cursor_to_pos((gwr*2)/5+2 , (gwc*2)/5);
    change_color_rgb(235,245,35);
    cout<<"2) MEDIUM";
    cursor_to_pos((gwr*2)/5+3 , (gwc*2)/5);
    change_color_rgb(245,35,35);
    cout<<"3) FAST";
    reset_color();
    cursor_to_pos((gwr*2)/5 , (gwc*2)/5+28);
    cin>>num_speed;
    switch(num_speed){
    case 1 : num_speed = 400 ; break ;
    case 2 : num_speed = 100 ; break ;
    case 3 : num_speed = 1 ; break ; }
    clear_screen();
}

void users_name()
{
    clear_screen();
    change_color_rgb(161,16,74);
    int gwc = get_window_cols() , gwr = get_window_rows();
    cursor_to_pos((gwr*2)/5 , (gwc*2)/5);
    cout<<"Please enter name of users."<<endl;
    change_color_rgb(255,192,217);
    cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5);
    cout<<"User 1 : "; 
    reset_color();
    cin>>u[n].name;
    change_color_rgb(255,192,217);
    cursor_to_pos((gwr*2)/5+2 , (gwc*2)/5);
    cout<<"User 2 : ";
    reset_color();
    cin>>u[m].name;
    clear_screen();

    change_color_rgb(161,16,74);
    cursor_to_pos((gwr*2)/5-5 , (gwc*2)/5);
    cout<<"Please choose your color : "<<endl;
    change_color_rgb(255,192,217);
    cursor_to_pos((gwr*2)/5-4 , (gwc*2)/5);
    cout<<"User 1 : "; 
    cursor_to_pos((gwr*2)/5-3 , (gwc*2)/5);
    change_color_rgb(255,0,96);
    cout<<"1) Color 1";
    cursor_to_pos((gwr*2)/5-2 , (gwc*2)/5);
    change_color_rgb(246,250,112);
    cout<<"2) Color 2";
    cursor_to_pos((gwr*2)/5-1 , (gwc*2)/5);
    change_color_rgb(0,223,164);
    cout<<"3) Color 3";
    cursor_to_pos((gwr*2)/5 , (gwc*2)/5);
    change_color_rgb(0,121,255);
    cout<<"4) Color 4";
    cursor_to_pos((gwr*2)/5-4 , (gwc*2)/5+10);
    reset_color();
    cin>>u[n].color;
    change_color_rgb(255,192,217);
    cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5);
    cout<<"User 2 : "; 
    cursor_to_pos((gwr*2)/5+2 , (gwc*2)/5);
    change_color_rgb(214,19,85);
    cout<<"1) Color 1";
    cursor_to_pos((gwr*2)/5+3 , (gwc*2)/5);
    change_color_rgb(249,74,41);
    cout<<"2) Color 2";
    cursor_to_pos((gwr*2)/5+4 , (gwc*2)/5);
    change_color_rgb(252,226,42);
    cout<<"3) Color 3";
    cursor_to_pos((gwr*2)/5+5 , (gwc*2)/5);
    change_color_rgb(48,227,223);
    cout<<"4) Color 4";
    cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5+10);
    reset_color();
    cin>>u[m].color;

    switch (u[n].color)
    {
    case 1:
        u[n].r = 255;
        u[n].g = 0;
        u[n].b = 96;
        break;
    case 2:
        u[n].r = 246;
        u[n].g = 250;
        u[n].b = 112;
        break;
    case 3:
        u[n].r = 0;
        u[n].g = 223;
        u[n].b = 164;
        break;
    case 4:
        u[n].r = 0;
        u[n].g = 121;
        u[n].b = 255;
        break;
    default:
        break;
    }

    switch (u[m].color)
    {
    case 1:
        u[m].r = 214;
        u[m].g = 19;
        u[m].b = 85;
        break;
    case 2:
        u[m].r = 249;
        u[m].g = 74;
        u[m].b = 41;
        break;
    case 3:
        u[m].r = 252;
        u[m].g = 226;
        u[m].b = 42;
        break;
    case 4:
        u[m].r = 48;
        u[m].g = 227;
        u[m].b = 223;
        break;
    default:
        break;
    }
    clear_screen();
}

void chart()
{
    if(bomb_x == u[n].x && bomb_y == u[n].y)
        {u[n].point -= 50; u[m].point += 7; gameover = true;}

    if(bomb_x == u[m].x && bomb_y == u[m].y)
        {u[m].point -= 50; u[n].point += 7; gameover = true;}

    if(u[n].x == u[m].x && u[n].y == u[m].y)
        {u[n].point -= 10; u[m].point -= 10; gameover = true;}

    if(u[n].x<=1 || u[n].x>=gwr || u[n].y<=2 || u[n].y>=gwc)
        {gameover = true; u[n].point -= 25; u[m].point += 4;}
    
    if(u[m].x<=1 || u[m].x>=gwr || u[m].y<=2 || u[m].y>=gwc)
        {gameover = true; u[m].point -= 25; u[n].point += 4;}

    for(int k = 0 ; k<tail_num1 ; k++)
        if(u[n].x == tail1_x[k] && u[n].y == tail1_y[k])
            {gameover = true; u[n].point -= 25; u[m].point += 6;}

    for(int k = 0 ; k<tail_num2 ; k++)
        if(u[m].x == tail2_x[k] && u[m].y == tail2_y[k])
            {gameover = true; u[m].point -= 25; u[n].point += 6;}

    for(int k = 0 ; k<tail_num2 ; k++)
        if(tail2_x[k] == u[n].x && tail2_y[k] == u[n].y)
            {gameover = true; u[n].point -= 25; u[m].point += 6;}

    for(int k = 0 ; k<tail_num1 ; k++)
        if(tail1_x[k] == u[m].x && tail1_y[k] == u[m].y)
            {gameover = true; u[m].point -= 25; u[n].point += 6;}

    int q1 , q2;
    if(u[m].point > u[n].point)
    {
        q1 = m;
        q2 = n;
    }
    else
    {
        q1 = n;
        q2 = m;
    }

    change_color_rgb(161,16,74);
    cursor_to_pos(3,0);
    cout<<"------------------------------------"<<endl;
    cout<<"|      ";
    change_color_rgb(138,205,215);
    cout<<"USERS";
    cursor_to_pos(4 , 19);
    change_color_rgb(161,16,74);
    cout<<" |    ";
    change_color_rgb(138,205,215);
    cout<<"POINTS";
    cursor_to_pos(4 , 34);
    change_color_rgb(161,16,74);
    cout<<"  |"<<endl; 
    cout<<"------------------------------------"<<endl;
    cout<<"| ";
    change_color_rgb(138,205,215);
    cout<<"1)  "; 
    change_color_rgb(255,192,217);
    cout<<u[q1].name<<"          ";
    cursor_to_pos(6 , 19);
    cout<<" :    ";
    change_color_rgb(242,242,203);
    cout<<u[q1].point<<"          ";
    cursor_to_pos(6 , 34);
    change_color_rgb(161,16,74);
    cout<<"  |"<<endl; 
    cout<<"------------------------------------"<<endl;
    cout<<"| ";
    change_color_rgb(138,205,215);
    cout<<"2)  "; 
    change_color_rgb(255,192,217);
    cout<<u[q2].name<<"          ";
    cursor_to_pos(8 , 19);
    cout<<" :    ";
    change_color_rgb(242,242,203);
    cout<<u[q2].point<<"          ";
    cursor_to_pos(8 , 34);
    change_color_rgb(161,16,74);
    cout<<"  |"<<endl; 
    cout<<"------------------------------------"<<endl;

    cursor_to_pos(10,0);

    for(int i=1 ; i<=gwr ; i++)
    {
        for(int j=1 ; j<=gwc ; j++)
        {
            if((i == 1 || i == gwr) && j<=gwc && j>=2)
            {
                change_color_rgb(156,216,255);
                cout<<"*";
            }

            else if((j == 2 || j == gwc) && i<=gwr)
            {
                change_color_rgb(156,216,255);
                cout<<"*";
            }

            else if(i == u[n].x && j == u[n].y)
            {
                change_color_rgb(u[n].r , u[n].g , u[n].b);
                cout<<"0";
            }

            else if(i == u[m].x && j == u[m].y)
            {
                change_color_rgb(u[m].r , u[m].g , u[m].b);
                cout<<"0";
            }

            else if(i == apple_x && j == apple_y)
            {
                change_color_rgb(145 , 255 , 34);
                cout<<"$";              
            }

            else if(i == bomb_x && j ==bomb_y)
            {
                change_color_rgb(93 , 3 , 171);
                cout<<"@";              
            }

            else
            {
                bool space = true;

                for(int k1 = 1 ; k1<tail_num1 ; k1++)
                {
                    if(i == tail1_x[k1] && j == tail1_y[k1])
                        {
                            change_color_rgb(u[n].r , u[n].g , u[n].b);
                            cout<<"o";
                            space = false;
                        }
                }

                for(int k2 = 1 ; k2<tail_num2 ; k2++)
                {
                    if(i == tail2_x[k2] && j == tail2_y[k2])
                        {
                            change_color_rgb(u[m].r , u[m].g , u[m].b);
                            cout<<"o";
                            space = false;
                        }
                }

                if(space)
                    cout<<" ";
            }
        }

        cout<<endl;
    }
    
    if(apple_x == u[n].x && apple_y == u[n].y)
        {u[n].point += 10 ; u[m].point -= 3 ; tail_num1++ ; random_apple();}

    else if(apple_x == u[m].x && apple_y == u[m].y)
        {u[m].point += 10 ; u[n].point -= 3 ; tail_num2++ ; random_apple();}

    int t;

    if(is_keyboard_hit())
    {
        t = getch();
        if(t == 224 || t == 0)
            t02 = getch();
        else
            t01 = t;
    }

    int help1_x = tail1_x[0] , help1_y = tail1_y[0];
    tail1_x[0] = u[n].x ;
    tail1_y[0] = u[n].y ;
    int helpp1_x , helpp1_y;

    for(int i=0 ; i<tail_num1 ; i++)
    {
        helpp1_x = tail1_x[i];
        helpp1_y = tail1_y[i];
        tail1_x[i] = help1_x;
        tail1_y[i] = help1_y;
        help1_x = helpp1_x;
        help1_y = helpp1_y;
    }

    switch (t01)
    {
        case 'w':
            u[n].x--;
            break;
        case 's':
            u[n].x++;
            break;
        case 'd':
            u[n].y++;
            break;
        case 'a':
            u[n].y--;
            break;
        default :
            break;
    }

    int help2_x = tail2_x[0] , help2_y = tail2_y[0];
    tail2_x[0] = u[m].x ;
    tail2_y[0] = u[m].y ;
    int helpp2_x , helpp2_y;

    for(int i=0 ; i<tail_num2 ; i++)
    {
        helpp2_x = tail2_x[i];
        helpp2_y = tail2_y[i];
        tail2_x[i] = help2_x;
        tail2_y[i] = help2_y;
        help2_x = helpp2_x;
        help2_y = helpp2_y;
    }

    switch (t02)
    {
        case 80:
            u[m].x++;
            break;
        case 72:
            u[m].x--;
            break;
        case 77:
            u[m].y++;
            break;
        case 75:
            u[m].y--;
            break;
        default :
            break;
    }
}

int hamin;

int game()
{
    clear_screen();
    int a = 27;
    gameover = false;
    random_bomb();
    random_apple();
    location();

    if(hamin == 0)
    {
        users_name();
        change_speed();
    }

    while(!gameover)
    {
        chart();
        delay(num_speed);
       //cout << "\033[2J\033[1;1H";
    }

    if(gameover)
    {
        delay(2000);
        hamin++;
        clear_screen();
        int q , i=0;
        if(u[n].point > u[m].point)
            q = n;
        else if(u[n].point < u[m].point)
            q = m;

        while(a != 1 && a != 2)
        {
            i++;
            change_color_rgb(235,245,35);
            cursor_to_pos(get_window_rows()*3/5-3 , get_window_cols()*2/5);
            cout<<"YOU LOST! CHOOSE AN OPTION : ";
            cursor_to_pos(get_window_rows()*3/5-2 , get_window_cols()*2/5);
            change_color_rgb(35,230,15);
            cout<<"1) PLAY AGAIN!";
            cursor_to_pos(get_window_rows()*3/5-1 , get_window_cols()*2/5);
            change_color_rgb(245,35,35);
            cout<<"2) MENU";

            if(i%2 == 0)
            {
                change_color_rgb(255,181,52);
                cursor_to_pos(get_window_rows()*3/5 , (get_window_cols()*2)/5);
                cout<<"* * * * * * * * * * * * * * *";
                cursor_to_pos(get_window_rows()*3/5+1 , (get_window_cols()*2)/5);
                cout<<"  ";
                cursor_to_pos(get_window_rows()*3/5+1 , (get_window_cols()*2)/5+27);
                cout<<" *";
                cursor_to_pos(get_window_rows()*3/5+2 , (get_window_cols()*2)/5);
                cout<<"* ";
                change_color_rgb(251,246,238);
                cout<<"THE WINNER";
                change_color_rgb(255,181,52);
                cout<<" : ";
                change_color_rgb(193,242,176);
                cout<<u[q].name;
                change_color_rgb(255,181,52);
                cout<<" => ";
                change_color_rgb(101,183,65);
                cout<<u[q].point;
                change_color_rgb(255,181,52);
                cursor_to_pos(get_window_rows()*3/5+2 , (get_window_cols()*2)/5+27);
                cout<<"  ";
                cursor_to_pos(get_window_rows()*3/5+3 , (get_window_cols()*2)/5);
                cout<<"  ";
                cursor_to_pos(get_window_rows()*3/5+3 , (get_window_cols()*2)/5+27);
                cout<<" *";
                cursor_to_pos(get_window_rows()*3/5+4 , (get_window_cols()*2)/5);
                cout<<"* * * * * * * * * * * * * * *";
            }

            else if(i%2 == 1)
            {
                change_color_rgb(113,29,176);
                cursor_to_pos(get_window_rows()*3/5 , (get_window_cols()*2)/5);
                cout<<" * * * * * * * * * * * * * * ";
                cursor_to_pos(get_window_rows()*3/5+1 , (get_window_cols()*2)/5);
                cout<<"* ";
                cursor_to_pos(get_window_rows()*3/5+1 , (get_window_cols()*2)/5+27);
                cout<<"  ";
                cursor_to_pos(get_window_rows()*3/5+2 , (get_window_cols()*2)/5);
                cout<<"  ";
                change_color_rgb(194,18,146);
                cout<<"THE WINNER";
                change_color_rgb(113,29,176);
                cout<<" : ";
                change_color_rgb(236,64,64);
                cout<<u[q].name;
                change_color_rgb(113,29,176);
                cout<<" => ";
                change_color_rgb(255,167,50);
                cout<<u[q].point;
                change_color_rgb(113,29,176);
                cursor_to_pos(get_window_rows()*3/5+2 , (get_window_cols()*2)/5+27);
                cout<<" *";
                cursor_to_pos(get_window_rows()*3/5+3 , (get_window_cols()*2)/5);
                cout<<"* ";
                cursor_to_pos(get_window_rows()*3/5+3 , (get_window_cols()*2)/5+27);
                cout<<"  ";
                cursor_to_pos(get_window_rows()*3/5+4 , (get_window_cols()*2)/5);
                cout<<" * * * * * * * * * * * * * * ";
            }

            if(is_keyboard_hit())
                a = getch();
            if(a == '1')
                a = 1;
            else if(a == '2')
                a = 2;
            else if( a != 27)
            {
                cursor_to_pos(get_window_rows()*3/5-4 , get_window_cols()*2/5);
                reset_color();
                cout<<"Sorry! please try it again."<<endl;
            }
            delay(150);
        }

        u[n].pt += u[n].point;
        u[m].pt += u[m].point;
        u[n].point = 0;
        u[m].point = 0;
    }

    gameover = false;
    return a;
}

void create_user(int& q , int g)
{
    int gwr = get_window_rows() , gwc = get_window_cols();
    clear_screen();
    cursor_to_pos(gwr*3/10-1 , gwc*2/5);
    change_color_rgb(161,16,74);
    cout<<"Choose one : ";
    for(int i =0 ; i<=helpful_i && i<ziz ; i++)
    {
    cursor_to_pos(gwr*3/10+i , gwc*2/5);
    change_color_rgb(255,192,217);
    cout<<i+1<<") User "<<i+1<<" : "<<u[i].name;
    }
    if(helpful_i<ziz-1)
    {
        cursor_to_pos(gwr*3/10+helpful_i+1 , gwc*2/5);
        cout<<helpful_i+2<<") Create a new user";
    }
    reset_color();
    cursor_to_pos(gwr*3/10-1 , gwc*2/5+14);
    int g0;
    cin>>g0;
    if(g0 == helpful_i+2 && helpful_i<ziz)
    {
        clear_screen();
        helpful_i++;
        q = helpful_i;
        change_color_rgb(161,16,74);
        cursor_to_pos((gwr*2)/5 , (gwc*2)/5);
        cout<<"Please enter name of user."<<endl;
        change_color_rgb(255,192,217);
        cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5);
        cout<<"User "<<q+1<<" : "; 
        reset_color();
        cin>>u[q].name;
        clear_screen();

        change_color_rgb(161,16,74);
        cursor_to_pos((gwr*2)/5 , (gwc*2)/5);
        cout<<"Please choose your color : "<<endl;
        change_color_rgb(255,192,217);
        cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5);
        cout<<"User "<<q+1<<" : "; 
        if(g == 1)
        {
            cursor_to_pos((gwr*2)/5+2 , (gwc*2)/5);
            change_color_rgb(255,0,96);
            cout<<"1) Color 1";
            cursor_to_pos((gwr*2)/5+3 , (gwc*2)/5);
            change_color_rgb(246,250,112);
            cout<<"2) Color 2";
            cursor_to_pos((gwr*2)/5+4 , (gwc*2)/5);
            change_color_rgb(0,223,164);
            cout<<"3) Color 3";
            cursor_to_pos((gwr*2)/5+5 , (gwc*2)/5);
            change_color_rgb(0,121,255);
            cout<<"4) Color 4";
            cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5+11);
            reset_color();
            cin>>u[q].color;

            switch (u[q].color)
            {
            case 1:
                u[q].r = 255;
                u[q].g = 0;
                u[q].b = 96;
                break;
            case 2:
                u[q].r = 246;
                u[q].g = 250;
                u[q].b = 112;
                break;
            case 3:
                u[q].r = 0;
                u[q].g = 223;
                u[q].b = 164;
                break;
            case 4:
                u[q].r = 0;
                u[q].g = 121;
                u[q].b = 255;
                break;
            default:
                break;
            }
        }

        else
        {
            cursor_to_pos((gwr*2)/5+2 , (gwc*2)/5);
            change_color_rgb(214,19,85);
            cout<<"1) Color 1";
            cursor_to_pos((gwr*2)/5+3 , (gwc*2)/5);
            change_color_rgb(249,74,41);
            cout<<"2) Color 2";
            cursor_to_pos((gwr*2)/5+4 , (gwc*2)/5);
            change_color_rgb(252,226,42);
            cout<<"3) Color 3";
            cursor_to_pos((gwr*2)/5+5 , (gwc*2)/5);
            change_color_rgb(48,227,223);
            cout<<"4) Color 4";
            cursor_to_pos((gwr*2)/5+1 , (gwc*2)/5+10);
            reset_color();
            cin>>u[q].color;

            switch (u[q].color)
            {
            case 1:
                u[q].r = 214;
                u[q].g = 19;
                u[q].b = 85;
                break;
            case 2:
                u[q].r = 249;
                u[q].g = 74;
                u[q].b = 41;
                break;
            case 3:
                u[q].r = 252;
                u[q].g = 226;
                u[q].b = 42;
                break;
            case 4:
                u[q].r = 48;
                u[q].g = 227;
                u[q].b = 223;
                break;
            default:
                break;
            }
        }

        clear_screen();
    }

    else if(g0 >= 1 && g0 <= helpful_i+1 && g0<=ziz)
        q = g0-1;

    else
    {
        cursor_to_pos(gwr*2/5-1 , gwc*2/5);
        cout<<"Sorry! please try it again."<<endl;
        create_user(q , g);
    }

}

void change_user()
{
    int gwr = get_window_rows() , gwc = get_window_cols();
    cursor_to_pos(gwr*2/5 , gwc*2/5);
    change_color_rgb(161,16,74);
    cout<<"Which user do you want to change? : ";
    cursor_to_pos(gwr*2/5+1 , gwc*2/5);
    change_color_rgb(255,192,217);
    cout<<"1) User 1";
    cursor_to_pos(gwr*2/5+2 , gwc*2/5);
    cout<<"2) User 2";
    cursor_to_pos(gwr*2/5 , gwc*2/5+37);
    reset_color();
    int g;
    cin>>g;

    if(g == 1)
        create_user(n , g);
    else if(g == 2)
        create_user(m , g);
    else
    {
        cursor_to_pos(gwr*2/5-1 , gwc*2/5);
        cout<<"Sorry! please try it again."<<endl;
        change_user();
    }

}

int main()
{
    init_clui();
    cursor_to_pos((get_window_rows()*2)/5 , (get_window_cols()*2)/5);
    change_color_rgb(8 , 2 , 163);
    cout<<"Please enter your option :"<<endl;
    cursor_to_pos((get_window_rows()*2)/5+1 , (get_window_cols()*2)/5);
    change_color_rgb(240 , 50 , 170);
    cout<<"1) Start"<<endl;
    cursor_to_pos((get_window_rows()*2)/5+2 , (get_window_cols()*2)/5);
    change_color_rgb(255,75,144);
    cout<<"2) Leader board"<<endl;
    cursor_to_pos((get_window_rows()*2)/5+3 , (get_window_cols()*2)/5);
    change_color_rgb(255,118,118);
    cout<<"3) Change user"<<endl;
    cursor_to_pos((get_window_rows()*2)/5+4 , (get_window_cols()*2)/5);
    change_color_rgb(255,205,75);
    cout<<"4) Change speed";
    cursor_to_pos((get_window_rows()*2)/5+5 , (get_window_cols()*2)/5);
    change_color_rgb(242,242,184);
    cout<<"5) How to play";
    cursor_to_pos((get_window_rows()*2)/5+6 , (get_window_cols()*2)/5);
    reset_color();
    cout<<"6) Exit"<<endl;
    int a;
    cursor_to_pos((get_window_rows()*2)/5 , (get_window_cols()*2)/5+27);
    cin>>a;
    if(a==1)
    {
        while(!gameover)
        {
            if(a == 1)
                a = game();
            else if(a == 2)
                {main(); clear_screen();}
        }
    }
    else if(a==2)
    {
        scoreboard();
        int t = 0;
        while(t != 27)
        {
            t = getch();
            if(t == 27)
            {
                clear_screen();
                main();
            }
        }
    }
    else if(a==3)
    {
        clear_screen();
        change_user();
        if(m == n)
        {
            clear_screen();
            cursor_to_pos((get_window_rows()*2)/5-1 , (get_window_cols()*2)/5);
            cout<<"Sorry! User 1 and User 2 are the same person. please try it again."<<endl;
            change_user();
        }
        main();
    }
    else if(a==4)
    {
        clear_screen();
        change_speed();
        main();
    }
    else if(a==6)
        {
            clear_screen();

            if(hamin == 0)
            {
                cursor_to_pos(get_window_rows()/2 , get_window_cols()/2);
                change_color_rgb(161,16,74);
                cout<<"BYE BYE!";
                delay(4000);
            }

            else
                for(int i=0 ; i < 80 ; i++)
                {
                    if(i%2 == 0)
                    {
                        change_color_rgb(255,181,52);
                        cursor_to_pos(get_window_rows()*3/10 , (get_window_cols()*2)/5);
                        cout<<"* * * * * * * * * * * * * * * ";
                        cursor_to_pos(get_window_rows()*3/10+1 , (get_window_cols()*2)/5);
                        cout<<"  ";
                        cursor_to_pos(get_window_rows()*3/10+1 , (get_window_cols()*2)/5+28);
                        cout<<" *";
                        cursor_to_pos(get_window_rows()*3/10+2 , (get_window_cols()*2)/5);
                        cout<<"* ";
                        change_color_rgb(251,246,238);
                        cout<<"THE WINNER";
                        change_color_rgb(255,181,52);
                        cout<<" : ";
                        change_color_rgb(193,242,176);
                        cout<<u[maximam(u , helpful_i)].name;
                        change_color_rgb(255,181,52);
                        cout<<" => ";
                        change_color_rgb(101,183,65);
                        cout<<u[maximam(u , helpful_i)].pt;
                        change_color_rgb(255,181,52);
                        cursor_to_pos(get_window_rows()*3/10+2 , (get_window_cols()*2)/5+28);
                        cout<<"  ";
                        cursor_to_pos(get_window_rows()*3/10+3 , (get_window_cols()*2)/5);
                        cout<<"  ";
                        cursor_to_pos(get_window_rows()*3/10+3 , (get_window_cols()*2)/5+28);
                        cout<<" *";
                        cursor_to_pos(get_window_rows()*3/10+4 , (get_window_cols()*2)/5);
                        cout<<"* * * * * * * * * * * * * * * ";

                        change_color_rgb(255,115,50);
                        cursor_to_pos(get_window_rows()*3/10+6 , (get_window_cols()*2)/5);
                        cout<<"     *";
                        change_color_rgb(255,247,138);
                        cout<<" SEE YOU AGAIN! ";
                        change_color_rgb(255,115,50);
                        cout<<"*";
                    }

                    else if(i%2 == 1)
                    {
                        change_color_rgb(113,29,176);
                        cursor_to_pos(get_window_rows()*3/10 , (get_window_cols()*2)/5);
                        cout<<" * * * * * * * * * * * * * * *";
                        cursor_to_pos(get_window_rows()*3/10+1 , (get_window_cols()*2)/5);
                        cout<<"* ";
                        cursor_to_pos(get_window_rows()*3/10+1 , (get_window_cols()*2)/5+28);
                        cout<<"  ";
                        cursor_to_pos(get_window_rows()*3/10+2 , (get_window_cols()*2)/5);
                        cout<<"  ";
                        change_color_rgb(194,18,146);
                        cout<<"THE WINNER";
                        change_color_rgb(113,29,176);
                        cout<<" : ";
                        change_color_rgb(236,64,64);
                        cout<<u[maximam(u , helpful_i)].name;
                        change_color_rgb(113,29,176);
                        cout<<" => ";
                        change_color_rgb(255,167,50);
                        cout<<u[maximam(u , helpful_i)].pt;
                        change_color_rgb(113,29,176);
                        cursor_to_pos(get_window_rows()*3/10+2 , (get_window_cols()*2)/5+28);
                        cout<<" *";
                        cursor_to_pos(get_window_rows()*3/10+3 , (get_window_cols()*2)/5);
                        cout<<"* ";
                        cursor_to_pos(get_window_rows()*3/10+3 , (get_window_cols()*2)/5+28);
                        cout<<"  ";
                        cursor_to_pos(get_window_rows()*3/10+4 , (get_window_cols()*2)/5);
                        cout<<" * * * * * * * * * * * * * * *";

                        change_color_rgb(40,130,30);
                        cursor_to_pos(get_window_rows()*3/10+6 , (get_window_cols()*2)/5);
                        cout<<"     *";
                        change_color_rgb(217,237,191);
                        cout<<" SEE YOU AGAIN! ";
                        change_color_rgb(40,130,30);
                        cout<<"*";
                    }

                    delay(150);
                }

            quit();
        }
    else if(a==5)
    {
        clear_screen();
        int gwr = get_window_rows() , gwc = get_window_cols();
        cursor_to_pos(gwr*3/10-4 , gwc/10);
        change_color_rgb(129,104,157);
        cout<<"* THIS GAME WAS DEVELOPED BY HANA LASHKARI *";
        cursor_to_pos(gwr*3/10-2 , gwc/10);
        change_color_rgb(3,14,69);
        cout<<"HOW TO PLAY :";
        cursor_to_pos(gwr*3/10 , gwc/10);
        change_color_rgb(255,208,236);
        cout<<"1) Player1 moves with the keys \"w\" for up, \"s\" for down, \"a\" for left and \"d\" for right.";
        cursor_to_pos(gwr*3/10+2 , gwc/10);
        cout<<"2) Player2 moves with the arrow keys.";
        cursor_to_pos(gwr*3/10+4 , gwc/10);
        cout<<"3) The goal of this game is to eat the apple, which is indicated by the \"$\".";
        cursor_to_pos(gwr*3/10+5 , gwc/10);
        cout<<"A snake that eats the apple gets 10 points and a snake that fails in eating the apple loses 3 points.";
        cursor_to_pos(gwr*3/10+7 , gwc/10);
        cout<<"4) The bomb is indicated by the \"@\", the snake that eats the bomb,";
        cursor_to_pos(gwr*3/10+8 , gwc/10);
        cout<<"loses 50 points and another snake gets 7 points.";
        cursor_to_pos(gwr*3/10+9 , gwc/10);
        cout<<"The game ends when one of the snakes eats the bomb.";
        cursor_to_pos(gwr*3/10+11 , gwc/10);
        cout<<"5) The bomb is indicated by the \"*\".";
        cursor_to_pos(gwr*3/10+12 , gwc/10);
        cout<<"If any of the snakes hits the wall, they lose 50 points and the other snake gets 7 points.";
        cursor_to_pos(gwr*3/10+14 , gwc/10);
        cout<<"6) If a snake hits itself or another snake,";
        cursor_to_pos(gwr*3/10+15 , gwc/10);
        cout<<"it loses 25 points and the other snake gains 6 points and the game is over.";
        cursor_to_pos(gwr*3/10+17 , gwc/10);
        cout<<"7) Finally, the snake with more points is the winner.";
        cursor_to_pos(gwr*3/10+20 , gwc/10);
        change_color_rgb(71,79,122);
        cout<<"Click on \"esc\" to come back to menu.";
        int t = getch();
        if(t == 27)
            main();
    }
    else{
        clear_screen();
        cursor_to_pos((get_window_rows()*2)/5-1 , (get_window_cols()*2)/5);
        cout<<"Sorry! please try it again."<<endl;
        delay(2000);
        main();
    }
    quit();
    return 0;
}