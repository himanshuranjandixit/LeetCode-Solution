class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        pair<int,int>coordinate = {0,0};
        char dir = 'N';
        int maxi=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i]<0){
                if(commands[i]==-1){                                      // W for -X direction
                    if(dir=='N') dir='E';                                 // E for +X direction
                    else if(dir=='E') dir='S';                             // N for +Y direction
                    else if(dir=='S') dir='W';                            // S for  -Y direction
                    else dir = 'N';
                }
                if(commands[i]==-2){
                    if(dir=='N') dir='W';
                    else if(dir=='E') dir='N';
                    else if(dir=='S') dir='E';
                    else dir = 'S';
                }

            }
            else{
                int step=commands[i];
                if(dir=='N'){
                    int c = coordinate.second+step;
                    int check=0;
                    for(int i=0;i<obstacles.size();i++){
                        if(coordinate.first==obstacles[i][0] && c >=obstacles[i][1] && coordinate.second<obstacles[i][1]){
                            coordinate.second=obstacles[i][1]-1;
                            check=1;
                            break;
                        }
                    }
                    if(check==0) coordinate.second+=step;
                }
                if(dir=='E'){
                    int c = coordinate.first+step;
                    int check=0;
                    for(int i=0;i<obstacles.size();i++){
                        if(c >=obstacles[i][0] && coordinate.second==obstacles[i][1] && coordinate.first<obstacles[i][0]){
                            coordinate.first=obstacles[i][0]-1;
                            check=1;
                            break;
                        }
                    }
                    if(check==0) coordinate.first+=step;
                }

                if(dir=='W'){
                    int c = coordinate.first-step;
                    int check=0;
                    for(int i=0;i<obstacles.size();i++){
                        if(c <=obstacles[i][0] && coordinate.second==obstacles[i][1] && coordinate.first>obstacles[i][0]){
                            coordinate.first=obstacles[i][0]+1;
                            check=1;
                            break;
                        }
                    }
                    if(check==0) coordinate.first-=step;
                }
                if(dir=='S'){
                    int c = coordinate.second-step;
                    int check=0;
                    for(int i=0;i<obstacles.size();i++){
                        if(coordinate.first==obstacles[i][0] && c<=obstacles[i][1] && coordinate.second>obstacles[i][1]){
                            coordinate.second=obstacles[i][1]+1;
                            check=1;
                            break;
                        }
                    }
                    if(check==0) coordinate.second-=step;
                }
            }
            int maxx=coordinate.first*coordinate.first + coordinate.second*coordinate.second;
            maxi=max(maxx,maxi);
        }
        return maxi ;
    }
};