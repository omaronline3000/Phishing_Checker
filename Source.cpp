#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include<stdlib.h>
using namespace std;
static int Total_points = 0;
    
vector< pair<string , int > > check_email(string File_name) {
    // important variables and data structures
        // variables for the process 
    int exist;
    bool save;  
        // variables and data structures for manipulation with word's file
    string C_data = "";
    string name = "";
    vector<string>data;
    vector< pair<string , int > > result;
    vector<char>points;

    fstream comp("phishing.txt"); 
        // variables and data structures for manipulation with mail's file
    fstream mails(File_name);
    vector<string>mail;
    string carr_mail = "";

    // save the phrases of the mails from the mail file
    while(getline(mails ,carr_mail)){
        mail.push_back(carr_mail);
    }

    // save words and points from word's file 
    while ( getline(comp, C_data) ) { 

        points.push_back(C_data[C_data.size()-1]); // save the points

        C_data.erase(C_data.size()-2 , 2); // delete the points and the blank from the string

        data.push_back(C_data); // add the string in the vector

    }

    for (int i = 0; i < data.size(); i++) { // select specific word
        name = data[i];
        for(int k = 0 ; k < mail.size() ; k++){ // select specific line
            exist = 0; 
                for(int l = 0 ; l < mail[k].size()  ; l++){ // select specific word
                    string comparison_string = mail[k].substr(l,name.size());

                        if(comparison_string == name){
                                exist++; // update the appearance times 
                            }
                }

                 if(exist>0){ 
                    Total_points += (int(points[i])-48) * exist; // update the score
                    save = true;
                    for(int j = 0 ; j < result.size() ; j++){ // search about the word in the result vector
                            if(name == result[j].first){
                                save = false;
                                result[j].second += exist; // if it exists , i will update the redundancy counter
                                break;
                            }
                    }

             if(save) // if the word is not in the result vector , i will put it                  
                result.emplace_back(name , exist);
        }

        }

    }

  comp.close(); mails.close();
  return result; // return the result vector
}

int main() {

    vector< pair<string , int> >res;
    char response_from_user;
    // get the file name
    string file;
    cout<<"Hello sir,\n\n- make sure that you entered the mail in the file which name is \"mail.txt\" \n\n";
        return_to_here_again:
    cout<<"Did you (y or n) : ";
    cin>>response_from_user;
                                    // ensuring that user entered the mail            
    if(response_from_user == 'n'){
        cout<<"\n Ok go and and put it in the file.\n";
        return 0;
    }
    else if(response_from_user != 'n' && response_from_user != 'y'){
        system("CLS");
        cout<<"\n wrong input, enter y or n\n";
        goto return_to_here_again;
    }

    file = "mail.txt";

res = check_email(file);
system("CLS");

for(int i = 0 ; i < res.size() ;i++){ // output the appearance words and their redundancies
    cout<<res[i].first<<" "<<res[i].second<<endl;
}
    // output the total points
    cout<<"the total points are : "<<Total_points;


}
