//
// Created by Marwan on 2/28/2024.
//
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


void sort(int arr[],int n, int &counter){ // brute force
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <n;j++){
            counter++;
            if(arr[i]<arr[j]){
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
// this function has nested loops so O(n^2) complexity
    for (int i=0; i < n; i++){
        cout << arr[i] << endl;
    }
}


void exp(int x, int n){
    float term = 1.0, approx = 1.0;

    for(int i = 0 ; i < n; i++){
        term *= x/i;
        approx += term;
    }
}

bool substrcheck(string a, string b){
    int counter = 0;
    for (int i = 0; i < b.size();i++){
        for(int j = i+1; j < b.size();j++){
            counter++;
            if(b.substr(i,j-1)==a){
                cout << counter << endl;
                return true;
            }
        }
    }
    cout << counter << endl;
    return false;
}

int saycheese(int height[],int size){
    int cheesecounter;
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++ ){
            if(height[i]<height[j]){
                cheesecounter++;
            }
        }

    }

    cout << "Cheese counter: " <<cheesecounter;
}

void transactions(int arr[],int n){
    int max = 0, curr = 0, start, end,counter = 0;

    for (int i = 0; i < n; i++){
       curr = arr[i] + curr;
       counter++;
       if(curr>max){
           max = curr;
           start = i;
       }
       if(curr-arr[i] == max-arr[i]){
           end = i;
       }
    }

    cout << "Rich from day " << start << " to " << end <<  endl << "Program took: " << counter << " steps";
}
int fun7(int i,int &counter){
    counter++;
    if(i%2){
        return(i++);
    } else{
        return fun7(fun7(i-1,counter),counter);
    }
}

// Function to compute factorial
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double sine(double x, int n){
    double result = 0,count = 0;

    for (int i = 0 ; i < n; i++) {
        count++;
        if (i % 2) {
            result = result - pow(x, 1 + 2 * i) / factorial(1 + 2 * i);
        } else {
            result = result + pow(x, 1 + 2 * i) / factorial(1 + 2 * i);
        }
    }
    cout <<"::: " << count << " :::";
    return result;
}

void function12 (char *s, int &count) {

    if (s[0] == '\0'){
        return;}
    function12 (s + 1,count);
    function12 (s + 1,count);
    count++;
}

void skullcalc(){
    srand(time(0));

    int num1, num2, operand, result, dummyresult;

    dummyresult = rand() % 2;
    cout << "Select operation." << endl << "1.Add" << endl <<"2.Subtract" <<
    endl <<"3.Multiply" << endl << "4.Divide"<< endl <<"Enter choice(1/2/3/4):";
    cin >> operand;
    cout << "Enter first number:";
    cin >> num1;
    cout << "Enter second number:";
    cin >> num2;

    switch (operand) {
        case 1:
            result = num1 + num2;
            dummyresult += num1 + num2;
            cout << num1 << " + " << num2 << " = " << dummyresult << endl;
            break;
        case 2:
            result = num1 - num2;
            dummyresult += num1 - num2;
            cout << num1 << " - " << num2 << " = " << dummyresult << endl;
            break;
        case 3:
            result = num1 * num2;
            dummyresult += num1 * num2;
            cout << num1 << " * " << num2 << " = " << dummyresult << endl;
            break;
        case 4:
            result = num1 / num2;
            dummyresult += num1 / num2;
            cout << num1 << " / " << num2 << " = " << dummyresult << endl;
            break;

    }
    string yesorno;

    cout << "Is this the correct? (yes/no):";
    cin >> yesorno;

    if(result == dummyresult){
        cout <<""
               "                                                                                          \n"
               "                                                                                          \n"
               "                                                                                          \n"
               "                                                                                          \n"
               "                        .:--=====-:.                  .:--=====-:.                        \n"
               "                    .=+##############*=:          .-+##############*=:                    \n"
               "                  -*####################*=.     -*####################*=.                 \n"
               "                -##########################=  -##########################=                \n"
               "              .*############################**############################*:              \n"
               "             .##############################################################:             \n"
               "             *###############################################################.            \n"
               "            -################################################################+            \n"
               "            *#################################################################            \n"
               "            *#################################################################            \n"
               "            +######################%%%%%##########%%%%%%######################            \n"
               "            -####################%@%###%@%######%@%####%%####################=            \n"
               "             +##########################################%###################*             \n"
               "              *#############***############################***#############*.             \n"
               "               +###########*++++##########################+++++###########+.              \n"
               "                :*#########*++++##%%##################%%##++++*#########*:                \n"
               "                  :+###############%%%##############%%%###############*-                  \n"
               "                    .+###############%%%%%%%%%%%%%%%%###############+:                    \n"
               "                      .=##################%%%%%%##################+.                      \n"
               "                         =######################################=.                        \n"
               "                           -*#################################=                           \n"
               "                             -*############################*-                             \n"
               "                               :*########################*-                               \n"
               "                                 :+####################*:                                 \n"
               "                                   .+################+:                                   \n"
               "                                     .=############+.                                     \n"
               "                                        =*#######=.                                       \n"
               "                                          -*###=                                          \n"
               "                                            --                                            "
               "";
    } else {
        cout <<""
               "                                                                                          \n"
               "                                     ..............:....                                  \n"
               "                               ...........::::.::::--------.                              \n"
               "                            ...:.............:::::::---======-.                           \n"
               "                         ..::::............:::::::::-----===+++=.                         \n"
               "                       .::::::............::::::::::::---====+++=-:                       \n"
               "                      :::::::..............:::::::::::::--===++**++-                      \n"
               "                    .::::::::..............::::::::::::---==++*****+=:                    \n"
               "                   .::--:::::.............::::::::::------==+*******+=:                   \n"
               "                   ::----::::::....:::::::::::::------=====+****##**++=.                  \n"
               "                  .::----::::::.::::::::::------------====++****##**+++:                  \n"
               "                  .---------:::::::::-------==----------==++*********+*=                  \n"
               "                 .:-------:::::::::::::---====--:::------====+*********=.                 \n"
               "                 .:------::::--------===--===-----===++===++++++*#*#***+-                 \n"
               "                 :--===:::-+**##**###***+=====--=***###########***####*+=                 \n"
               "                 :-===-:=*####******###++=====++*#####*#*#####****####*+=.                \n"
               "                 :-===-*##########*###**=--:-=**####%#######**++==**##*+=                 \n"
               "                 :-=+=:*#####****#%###*+=----=***##%%%%%#**+==-=--=**#*+-                 \n"
               "                 .-=+-:+*##***+*+*#%%%*-=--::-*####%%%%##*+==----:=#*#*+.                 \n"
               "                  -==-:=####**+++++#@*==--:+#**#####%%##**+==---::+#***+                  \n"
               "                  :=--::=####****++++=-:::=##**####**#***++=---::-*#***-                  \n"
               "                  .-:-:::-*#####*++=-::::=#*##**#***===++++**=---+*#*++:                  \n"
               "                  :::::::::--===--:::::::#########*+=----=======+***#*+-                  \n"
               "                  :-::::::-==-==++=----:+*######+=**==+****++*+++**##**:                  \n"
               "                   :-::::--====+=--=---+#*######++*+=+*++++=====+**#*+=                   \n"
               "                    :--:---=====-==--::*#%%#*#%%#+*++**++======+**##+.                    \n"
               "                     :=+=++*++=--==--::-*###+##%*=++*+*++++***###**+:                     \n"
               "                      --===***+=::----:---::-++--=+***********##***-                      \n"
               "                      .=+==++=++-:--:-:::::::--====+******=--###**=                       \n"
               "                       .:---*. ==::---:::-:---:===--*+###*  +##*-:                        \n"
               "                         .-:+- :=----:-:.-:-=:-==-=:+**##+ -###*                          \n"
               "                          -:-+::::-:-:=::-.:=-:==-+-=*++=-:#*##+                          \n"
               "                          :-:==-:::..:: :...:..:-:=--+====*#*#*=                          \n"
               "                          :-::-:::::::::-:::-::-=-===+==+*#****-                          \n"
               "                          -:::::::::-:.:-::.:.=:---==++*#*++***-                          \n"
               "                          ---:::::---:---:=:=:+-=:=+++**+++****-                          \n"
               "                          .--:::::::--=------==-=-++*+++*++**#*.                          \n"
               "                           .-::::--::--------====+++++*#******.                           \n"
               "                            .-::::::::::-:::-=-===++=+*#**##+                             \n"
               "                              :-----::::::::-===----+*###*=.                              \n"
               "                                 :-=-::.::-=====---+*##*:                                 \n"
               "                                   .:--===+***+=++**+-.                           ";
    }



}


int main(){
    int cnt4 = 0;

    for (int i = 1; i <= 1000-1; i++){
        for (int j = i+1; j <= 1000; j++){
            cnt4++;
        }

    }


    int ex[]={5,5,5,0,0,0,-5,2,1,3,4,4,5,15,0,0,0};

    transactions(ex,16);

    bool x= 0   %2;

    cout << endl << x;
    int sds=0;
    fun7(1,sds);
    cout << endl << sine(90*M_PI/180,15);
    string fruit = "mango";
    char *chart = &fruit.at(0);
    int numbers= 0;
    function12(chart, numbers);\

    cout << endl;

    skullcalc();


}