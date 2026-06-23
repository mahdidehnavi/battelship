#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void board(char arr[10][10])
{

    cout << "  ";
    for(int i = 0; i < 10; i++)
    {
        cout << "   " << i + 1;
    }
    cout << "   " << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << "    ";

        for(int j = 0; j < 10; j++)
        {
            cout << "---" << " ";
        }
        cout << endl;

        if(i < 9)
            cout << i + 1 << "  ";
        else
            cout << 10 << " ";


        for(int j = 0; j < 10; j++)
        {
            cout << "| ";
            if(arr[i][j] == '*')
                cout << "* ";
                
            else if(arr[i][j] == '#')
            {
                cout << "# " ;
            }
                
            else
                cout << ". ";
        }
        cout << "|" << endl;
    }
    cout << "    ";

    for(int j = 0; j < 10; j++)
        cout << "---" << " ";
    cout << endl;
}



bool getship(char array[10][10], int tool,int start[5][2],int t)
{
     
    while(1)
    {
        int x = rand() % 10;               
        int y = rand() % (11 - tool);      
        bool barkhord = true;

        for(int i = 0; i < tool; i++) 
        {
            if(array[x][i + y] == '*')
            {
                barkhord = false;
                break;
            }
        }

        if(barkhord) 
        {  
            
            for(int j = 0; j < tool; j++)
            {
                array[x][y + j] = '*';
            }
            start[t][0] = x ;
            start[t][1] = y ;
            

            return true;  
        }
    }

    return false; 
}

void namayesh_shlik(char battlshib[10][10],int x,int y)
{
    if(battlshib[x-1][y-1] == ('*'))
    {
        cout <<"Hit! Shot was successful." << endl; 
        battlshib[x-1][y-1] = '#' ;
        return ;
    }

    else if(battlshib[x-1][y-1] == '#')

    {
        cout <<"Already fired here."  << endl ;
        
    }

    else
    {
        if(battlshib[x-1][y-1] == '.')
        {
            cout << "Miss! Shot was unsuccessful." <<endl ;
            return ;
        }
    }   
}
 


void scan(char jadval[10][10])
{
    int t1 ;
    int t2 ;

    do
    {
        cout << "Enter mokhtasad: " << endl;
        cin >> t1 >> t2;
    } while (t1 < 0 || t2 < 0 || t1 > 7 || t2 > 7); 
    
    bool found_ship = false; 

    for(int i = t1; i < t1 + 4; i++)
    {
        for(int j = t2; j < t2 + 4; j++)
        {
            if(jadval[i][j] == '*')
            {
                found_ship = true;  
            }
        }
    }

    if(found_ship)
    {
        cout << "Ship Detected\n";
    }

    else
    {
        cout << "No Ship in Area\n";        
    }
}


void repaired(char map[10][10], int start[5][2], int size_ship[5])
{
    for(int i = 0; i < 5; i++)
    {
        int x = start[i][0];
        int y = start[i][1];
        int k = size_ship[i];

        for(int j = 0; j < k; j++)
        {
            if( map[x][y + j] == '#')
            {
                map[x][y + j] = '*';
                cout << "your ship has repaired *-*" << endl;
                return;
            }
        }
    }
}


void harekat_ship(char makan[10][10],int start[5][2],int size_ship[5])
{
   // int up = 0 ;
   // int down = 1 ;
   // int right = 2 ;
   // int left = 3 ;

            for(int j = 0;j < 5;j++)  
            {

                int k = size_ship[j] ;
                int x = start[j][0] ;
                int y = start[j][1] ;

                bool destroyed_all = true ;
                for(int m = 0; m < k; m++)
                {
                   if(makan[x][y + m] == '*')
                    {
                         destroyed_all   = false;
                         break;
                    }
                }

                if(destroyed_all )
                {
                    continue;
                }
                int n = rand() % 4 ;
                bool oky = true ;
                    
                if(n == 0)
                {
                    
                    bool canmove = true ;
                    bool oky = true ;
                    for(int m = 0; m < k;m++)
                    {
                        int x_new = x - 1 ;
                        int y_new = y + m ;
                        if(x_new < 0||x_new > 9 || y_new < 0||y_new > 9 ||makan[x_new][y_new] != '.')
                        {
                            oky = false ;
                            break ;
                        }

                    }

                    if(oky)
                    {  
                        cout << "succes move ship\t" << j + 1 << endl ; 
                        for(int m = 0;m < k;m++)
                        {
                            char current = makan[x][y + m]  ;
                            makan[x - 1][y + m] = current ;
                            makan[x][y + m] = '.' ; 
                        }
                        start[j][0] = x - 1 ;  
                        start[j][1] = y ;   
                    }

                    else if(!oky)
                    {
                        for(int m = 0;m < k;m++)
                        {
                            int x_new2 = x + 1 ;
                            int y_new2 = y + m ;
                        
                            if(x_new2 < 0 ||x_new2 > 9 || y_new2 < 0||y_new2 > 9 ||makan[x_new2][y_new2] != '.')
                             {
                                 canmove = false ;
                                 break ;
                             }
                        }
                         if(canmove)
                        {
                           cout << "succes move ship\t" << j + 1 << endl ; 
                           for(int m = 0;m < k;m++)
                           {
                            char current = makan[x][y + m]  ;
                            makan[x + 1][y + m] = current ;
                            makan[x][y + m] = '.' ;
                           }
                           start[j][0] = x + 1;
                           start[j][1] = y;

                        }
                        else if(!canmove)
                        {
                            cout << "un success move ship \t" << j + 1 << endl ;
                            for(int m = 0; m < k; m++)
                            {
                                char current = makan[x][y + m] ;
                                makan[x][y + m] = current ;
                            }
                        }
                        
                    }
                    
                }



                else if(n == 1)
                {
                    bool canmove = true ;
                    for(int m = 0; m < k; m++)
                    {
                        int x_new = x + 1 ;
                        int y_new = y + m ;
                        if(x_new < 0||x_new > 9 || y_new < 0||y_new > 9 ||makan[x_new][y_new] != '.')
                        {
                            oky = false ;
                            break ;
                        }
                    }

                    if(oky)
                    {
                        cout << "succes move ship\t" << j + 1 << endl ; 
                        for(int m = 0; m < k; m++)
                        {
                            char current = makan[x][y + m] ;
                            makan[x + 1][y + m] = current ;
                            makan[x][y + m] = '.' ;
                        }
                           start[j][0] = x + 1;
                           start[j][1] = y;
                    }
                    else if(!oky)
                    {
                        for(int m = 0; m < k; m++)
                        {
                            int x_new2 = x - 1 ;
                            int y_new2 = y + m ;

                            if(x_new2 < 0 ||x_new2 > 9 || y_new2 < 0||y_new2 > 9 ||makan[x_new2][y_new2] != '.')
                            {
                                canmove = false ;
                                break ;
                            }
                        }

                        if(canmove)
                        {
                            cout << "succes move ship\t" << j + 1 << endl ; 
                            for(int m = 0; m < k; m++)
                            {
                                char current = makan[x][y + m] ;
                                makan[x - 1][y + m] = current ;
                                makan[x][y + m] = '.' ;
                            }
                            start[j][0] = x - 1 ;  
                            start[j][1] = y ;
                        }
                        else if(!canmove)
                        {
                            cout << "un success move ship \t" << j + 1 << endl ;
                            for(int m = 0; m < k; m++)
                            {
                                char current = makan[x][y + m] ;
                                makan[x][y + m] = current ;
                            }
                        }
                    }
                }



                else if(n == 2)
                {
                    bool canmove = true ;
                    bool oky = true ;
                    for(int m = 0; m < k; m++)
                    {
                        int x_new = x ;
                        int y_new = y + m + 1 ;
                        if(x_new < 0||x_new > 9 || y_new < 0||y_new > 9 ||makan[x_new][y_new] != '.')
                        {
                            oky = false ;
                            break ;
                        }
                    }

                    if(oky)
                    {
                        cout << "succes move ship\t" << j + 1 << endl ; 
                        for(int m = 0; m < k; m++)
                        {
                            char current = makan[x][y + m] ;
                            makan[x][y + m + 1] = current ;
                            makan[x][y + m] = '.' ;
                        }
                        start[j][0] = x;
                        start[j][1] = y + 1;
                    }
                    else if(!oky)
                    {
                        for(int m = 0; m < k; m++)
                        {
                            int x_new2 = x ;
                            int y_new2 = y + m - 1 ;

                            if(x_new2 < 0 ||x_new2 > 9 || y_new2 < 0||y_new2 > 9 ||makan[x_new2][y_new2] != '.')
                            {
                                canmove = false ;
                                break ;
                            }
                        }

                        if(canmove)
                        {
                            cout << "succes move ship\t" << j + 1 << endl ; 
                            for(int m = 0; m < k; m++)
                            {
                                char current = makan[x][y + m] ;
                                makan[x][y + m - 1] = current ;
                                makan[x][y + m] = '.' ;
                            }
                            start[j][0] = x;
                            start[j][1] = y - 1;

                        }
                        else if(!canmove)
                        {
                            cout << "un success move ship \t" << j + 1 << endl ;
                            for(int m = 0; m < k; m++)
                            {
                                char current = makan[x][y + m] ;
                                makan[x][y + m] = current ;
                            }
                        }
                    }
                }


                if(n == 3)
                {
                    bool canmove = true ;
                    bool oky = true ;
                    for(int m = 0; m < k; m++)
                    {
                        int x_new = x ;
                        int y_new = y + m - 1 ;
                        if(x_new < 0||x_new > 9 || y_new < 0||y_new > 9 ||makan[x_new][y_new] != '.')
                        {
                            oky = false ;
                            break ;
                        }
                    }

                    if(oky)
                    {
                        cout << "succes move ship\t" << j + 1 << endl ; 
                        for(int m = 0; m < k; m++)
                        {
                            char current = makan[x][y + m] ;
                            makan[x][y + m - 1] = current ;
                            makan[x][y + m] = '.' ;
                        }
                        start[j][0] = x;
                        start[j][1] = y - 1;

                    }
                    else if(!oky)
                    {
                        for(int m = 0; m < k; m++)
                        {
                            int x_new2 = x ;
                            int y_new2 = y + m + 1 ;

                            if(x_new2 < 0 ||x_new2 > 9 || y_new2 < 0||y_new2 > 9 ||makan[x_new2][y_new2] != '.')
                            {
                                canmove = false ;
                                break ;
                            }
                        }

                        if(canmove)
                        {
                            cout << "succes move ship\t" << j + 1 << endl ; 
                            for(int m = 0; m < k; m++)
                            {
                                char current = makan[x][y + m] ;
                                makan[x][y + m + 1] = current ;
                                makan[x][y + m] = '.' ;
                            }
                            start[j][0] = x;
                            start[j][1] = y + 1;

                        }
                        else if(!canmove)
                        {
                            cout << "un success move ship \t" << j + 1 << endl ;
                            for(int m = 0; m < k; m++)
                            {
                                char current = makan[x][y + m] ;
                                makan[x][y + m] = current ;
                            }
                        }
                    }
                }
            }         
}



bool end_game(char Array[10][10] ,  int start[5][2] , int tol_ship[5])
{
    bool all_destroyed = true;
    for(int m = 0;m < 5;m++ )
    {
        int x = start[m][0] ;
        int y = start[m][1] ;
        int k = tol_ship[m] ;
        for(int t = 0;t < k;t++)
        {
            if(Array[x][y + t] !='#' )
            {
                all_destroyed = false;
                break ;
            }
        }

    }

    if(all_destroyed )
    {
        cout << "end paly\t" <<"Congratulations! You have won the game."<<endl ;
        return true ;
    }

    return false ;
}


int main()
{

    string name1 ;
    cout<<"* welcome to game battleship * ----> *__* "<< endl ;
    cout << "player 1---->"<<endl ;
    cin >> name1 ; 
    int x1 ;
    int y1 ;
    int start[5][2] ;
    char arr[10][10] ;

    string name2 ;
    cout <<  "player 2---->"<<endl ; 
    cin >> name2 ;
    int x2 ;
    int y2 ;
    int start2[5][2] ;
    char arr2[10][10] ;

    srand(static_cast<unsigned int>(time(0))) ;
    int tekrar_repaired = 0 ;

    int tekrar_repaired2 = 0 ;

    int turn = 1 ;
    for(int i = 0;i < 10;i++)
    {
        for(int j = 0;j < 10;j++)
            {
                arr[i][j] = '.' ;
            }
    }
    int tool_ship[5] ={5,4,3,3,2} ;
    for(int i = 0; i < 5; i++)
    {
        if(getship(arr, tool_ship[i],start,i))
        {
                //cout << "input ship  " << (i + 1) << "\tsuccess playr 1" << endl;
                //cout << "start mokhtasad ship" << start[i][0] <<endl ;
                //cout <<  "start mokhtasad ship" << start[i][1] <<endl ;
        }
        else 
        {
            cout << "input ship by tool " << (i + 1) << "failed" << endl;
        }
    }



    for(int i = 0;i < 10;i++)
        {
            for(int j = 0;j < 10;j++)
            {
                arr2[i][j] = '.' ;
            }
        }
        int tool_ship2[5] ={5,4,3,3,2} ;

        for(int i = 0; i < 5; i++)
        {
            if(getship(arr2, tool_ship2[i],start2,i))
            {
                //cout << "input ship  " << (i + 1) << "\tsuccess player 2" << endl;
                //cout << "start mokhtasad ship" << start[i][0] <<endl ;
                //cout <<  "start mokhtasad ship" << start[i][1] <<endl ;
            }
            else 
            {
                cout << "input ship by tool " << (i + 1) << "failed" << endl;
            }
        }    



    while(1)
    {
        if(turn == 1)
        {
             cout << " what do you ?"<<endl ;
            cout << "1.Fire  2.Scan  3.Repair\n";
            
            int choice;
            cin >> choice;
            switch (choice)
            {
                case 1:
                {
                    cout << "Enter fire coordinates (x y): " <<endl ;
                    cin >> x1 >> y1;

                    if(x1 >= 1 && x1 <= 10 && y1 >= 1 && y1 <= 10)
                    {
                        cout << name1 <<endl ;
                        namayesh_shlik(arr2, x1, y1);
                    }
                    else
                    {
                        cout << "Invalid coordinates!" << endl;
                    }
                    break;
                }   

                case 2:
                    scan(arr2);
                    break;
                
                    case 3:

                if(tekrar_repaired < 3) 
                {
                    repaired(arr, start, tool_ship);
                    tekrar_repaired++;
                } 
                else
                {
                    cout << "You have already repaired 3 times!" << endl;
                }
                    break;


                default:
                    cout << "wrong choice" << endl;
            }
            cout << name1 <<endl ;

            //board(arr) ;

            harekat_ship(arr,start, tool_ship) ;

            cout << name1 <<endl ;

            board(arr) ;

            if(end_game(arr,start,tool_ship) )
            {
                cout  <<name1 <<"*-*\t"<< "Congratulations! You have won the game."<<endl ;
                break ;
            }
            turn = 2 ;
        }

        else if(turn == 2)
        {
            cout << " what do you ?"<<endl ;
            cout << "1.Fire  2.Scan  3.Repair\n";
            
            int choice2 ;
            cin >> choice2;

            switch (choice2)
            {
                case 1:
                {
                    cout << "Enter fire coordinates (x y): " <<endl ;
                    cin >> x2 >> y2;

                    if(x2 >= 1 && x2 <= 10 && y2 >= 1 && y2 <= 10)
                    {
                        cout <<name2 <<endl ;
                        namayesh_shlik(arr, x2, y2);
                    }
                    else
                    {
                        cout << "Invalid coordinates!" << endl;
                    }
                    break;
                }

                case 2:
                    scan(arr);
                    break;

                    case 3:

                if(tekrar_repaired2 < 3) 
                {
                    repaired(arr2, start2, tool_ship2);
                    tekrar_repaired2++;
                } 
                else
                {
                    cout << "You have already repaired 3 times!" << endl;
                }
                    break;

                default:
                    cout << "wrong choice" << endl;
            }
            cout << name2 <<endl;

           // board(arr2) ;

            harekat_ship(arr2,start2, tool_ship2) ;

            cout << name2 <<endl;
            
            board(arr2) ;
            if( end_game(arr2,start2,tool_ship2)) 
            {
                cout  <<name2 <<"*-*\t"<< "Congratulations! You have won the game."<<endl ;
                break ;
            }
            turn = 1;
        }
    }

    return 0;
}