class Solution {
public:
    string intToRoman(int nums) {
        string roman="";
        
        //count 1000
        for(int i=1;i<=nums/1000;i++){
            roman=roman+'M';
        }
        nums=nums-(nums/1000)*1000;
        //check for 900
        if(nums/900==1){
            roman=roman+"CM";
            nums=nums-900;
        }
         //count 500
        for(int i=1;i<=nums/500;i++){
            roman=roman+'D';
        }
        nums=nums-(nums/500)*500;
        //check for 400
        if(nums/400==1){
            roman=roman+"CD";
            nums=nums-400;
        }
         //count 100
        for(int i=1;i<=nums/100;i++){
            roman=roman+'C';
        }
        nums=nums-(nums/100)*100;
        //check for 90
        if(nums/90==1){
            roman=roman+"XC";
            nums=nums-90;
        }
         //count 50
        for(int i=1;i<=nums/50;i++){
            roman=roman+'L';
        }
        nums=nums-(nums/50)*50;
        //check for 40
        if(nums/40==1){
            roman=roman+"XL";
            nums=nums-40;
        }
         //count 10
        for(int i=1;i<=nums/10;i++){
            roman=roman+'X';
        }
        nums=nums-(nums/10)*10;
        //check for 9
        if(nums/9==1){
            roman=roman+"IX";
            nums=nums-9;
        }
         //count 5
        for(int i=1;i<=nums/5;i++){
            roman=roman+'V';
        }
        nums=nums-(nums/5)*5;
        //check for 4
        if(nums/4==1){
            roman=roman+"IV";
            nums=nums-4;
        }
        //count 1
       //cout<<nums<<endl;
        for(int i=1;i<=nums;i++){
            //cout<<"why not here"<<" ";
            roman=roman+'I';
        }
        return roman;   
    }
};