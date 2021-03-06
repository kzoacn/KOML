#ifndef KOML_HPP
#define KOML_HPP

#include<map>
#include<vector>
class KOML{
private:
    std::map<std::string,std::string>M;

    std::vector<std::string> split(std::string s,char sep){
        std::vector<std::string>res;
        res.push_back("");
        for(int i=0;i<(int)s.length();i++){
            char c=s[i];
            if(c==sep){
                res.push_back("");
            }else{
                res.back()+=c;
            }
        }

        return res;
    }

public:

    void parse(std::string input){
        M.clear();
        std::vector<std::string> lines=split(input,'\n');
        std::vector<std::string> chunks;
        for(int i=0;i<(int)lines.size();i++){
            std::string &s=lines[i];
            for(int j=0;j<s.length();j++){
                if(s[j]=='='){
                    M[s.substr(0,j)]=s.substr(j+1,s.length()-j-1);
                    break;
                }
            }
        }
    }

    std::string serialize(){
        std::string res;
        for(std::map<std::string,std::string>:: iterator it=M.begin();
            it!=M.end();it++){
                res+=it->first+'='+it->second+'\n';
            }
        return res;
    }
    

    
    int getint(std::string name){
        int x;
        sscanf(M[name].c_str(),"%d",&x);
        return x;
    }

    std::string getstr(std::string name){
        return M[name];
    }

    
};

#endif
