#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void getBooks(vector<string> &a){
    ifstream filess("BookList.txt");
    if(!filess){
        cerr<<"File Not Found"<<endl;
    }
    else{
        while(!filess.eof()){
            string line;
            getline(filess,line);
            a.push_back(line);
        }
    }
}
double no_of_words(string n){
    double wcount=0;
    ifstream files(n);
    if(!files){
        cerr<<"Book Not Found"<<endl;
    }
    else{
        while(!files.eof()){
            string line;
            getline(files,line);
            for(auto i:line){
                if(i==' ') wcount++;
            }
        }
    }
    files.close();
    return wcount;
}
void eraser(unordered_map<string,int> &a){
    vector<string> dontc={"A","THE","OF","IN","AND","AN","TO"};
    for(int i=0;i<7;i++){
        a[dontc[i]]=0;
    }
}
void word_maker(unordered_map<string,int> &a, string n){
    string temp="";
    ifstream booknum(n);
    if(!booknum){
        cerr<<"File Not Found"<<endl;
    }
    else{
        while(!booknum.eof()){
            string line;
            vector<string> dontc={"A","THE","OF","IN","AND","AN","TO"};
            getline(booknum,line);
            for(int i=0;i<line.size();i++){
                temp+=toupper(line[i]);
                if(line[i]==' '){
                    for(string i: dontc){
                        if(temp==i){
                            temp="";
                            break;
                        }
                    }  
                    if(temp!=""){ 
                        a[temp]++;
                        temp="";
                    }
                }
            }
        }
    booknum.close();
    }
}
vector<pair<string,int>> pair_maker(unordered_map<string,int> &myMap){
    vector<pair<string, int>> vec(myMap.begin(), myMap.end());
    sort(vec.begin(), vec.end(),
            [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second > b.second;
            });
        return vec;
}
void book10(double a[64][64],vector<vector<int>> &b){ 
    for(int m=0;m<10;m++){
        vector<int>temp;
        double max=0;
        int k=0;
        int l=0;
        for(int i=0;i<64;i++){
            for(int j=0;j<64;j++){
                if(max < a[i][j]){
                    max=a[i][j];
                    k=i;
                    l=j;
                }
            }
        }
        a[k][l]=0;
        temp.push_back(k);
        temp.push_back(l);
        b.push_back(temp);
    }

}
class books{
    private:
        string name;
        double twords;
        unordered_map<string,int> words;
        vector<pair<string, int>> pairs;
    public:
        void set_name(string t){
            name=t;
            string n="Book-Txt/"+name+".txt"; 
            twords=no_of_words(n);
            word_maker(words,n);
            eraser(words);
            pairs=pair_maker(words);  
        }
        double operator ==(books &obj){
            double counter=0;
            for(int i=0;i<100;i++){
                for(int j=0;j<100;j++){
                   if(pairs[i].first == obj.pairs[j].first){
                    counter+=pairs[i].second/twords + obj.pairs[j].second/obj.twords;
                   }
                }
            }
            return counter;
        }
};
int main(){
    vector <string> bnames; //stores book names
    double simMat[64][64];  //similarity matrix
    vector<vector<int>> boi; // will hold indexs of similar books
    getBooks(bnames);  // function to get all book names 

    int vsize=bnames.size();
    books  book[vsize];  // object array of books 
    for(int i=0;i<vsize;i++){
        string t= bnames[i]; // takes each name
        book[i].set_name(t);  //assigns name to object array
    }

    for(int i=0;i<64;i++){      // comparing two books
        for(int j=0;j<64;j++){
            if(j<i) {
                double cov= (book[i]==book[j]);
                simMat[i][j]=cov;
            }else{
                simMat[i][j]=0;
            }
        }
    }
    
    book10(simMat, boi);  //function to get 10 most similar books
    for(int i=0;i<10;i++){
        cout<<bnames[boi[i][0]]<<" - is similar to - "
        <<bnames[boi[i][1]]<<endl;
    }


    return 0;     

}
