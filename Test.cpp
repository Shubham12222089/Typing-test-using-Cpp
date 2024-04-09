#include<iostream>
#include<chrono>
#include<iomanip>
#include<string>
#include<algorithm> // For std::count_if
#include<cctype>    // For std::isspace
using namespace std;

int main(){
    string original_text = "This is a typing test";

    cout<<"Type the following text."<<endl;

    cout<<original_text<<endl;

    auto start_time = chrono::steady_clock::now();
    string typed_text;
    getline(cin,typed_text);
    auto end_time = chrono::steady_clock::now();

    auto elapsed_time = chrono::duration_cast<chrono::seconds>(end_time-start_time);

    int correct_chars = 0;
    for(size_t i = 0;i<original_text.size();i++){
        if(i<typed_text.size() && original_text[i]==typed_text[i]){
            correct_chars++;
        }
    }

    //for counting nomber of words
    int words = 1; // Start with 1 word for non-empty input
    for(auto c : typed_text){
        if(isspace(c)){
            words++;
        }
    }

    double accuracy = static_cast<double>(correct_chars)/original_text.size() * 100;

    double typing_speed = static_cast<double>(typed_text.size())/elapsed_time.count();

    double words_speed = (elapsed_time.count() > 0) ? (static_cast<double>(words) * 60 / elapsed_time.count()) : 0.0;

    cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"|                                                                     |"<<endl;
    cout<<"|                                     Result                          |"<<endl;
    cout<<"|                                                                     |"<<endl;
    cout<<"|              Accuracy : "<<fixed<<setprecision(2)<< accuracy<<"%"<<"                                     |"<<endl;

    cout<<"|              Typing speed : "<<fixed<<setprecision(2)<<typing_speed<<" characters per seconds"<<"             |"<<endl;

    cout<<"|              Typing speed : "<<fixed<<setprecision(2)<<words_speed<<" words per minute"<<"                 |"<<endl;

    cout<<"|              You took "<<elapsed_time.count()<<" Sec to complete the test."<<"                   |"<<endl;

    cout<<"|                                                                     |"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    return 0;

}