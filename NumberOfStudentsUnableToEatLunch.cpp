class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        bool noChange = true;
        int top = 0, delCount = 0;
        while(noChange){
            noChange = true;
            if(delCount * 2 > students.size()){
                erase_if(students, [](int x) {return (x == -1) ? true : false;});
                erase_if(sandwiches, [](int x) {return (x == -1) ? true : false;});
                delCount = 0;
                top = 0;
            }
            for(int i = 0; i < students.size() && top < sandwiches.size(); i++){
                if(students[i] == sandwiches[top]){
                    students[i] = -1;
                    sandwiches[top++] = -1;
                    delCount++;
                    noChange = false;
                }
                else if(students[i] == -1) continue;
            }
            if(top == sandwiches.size()) return 0;
            if(noChange){
                erase_if(students, [](int x) { return (x == -1) ? true : false;});
                top = 0; delCount = 0;
                break;
            }
            else{
                noChange = true;
            }
        }
        return students.size();
    }
};
