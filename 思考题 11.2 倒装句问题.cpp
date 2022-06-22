//对于一个英文句子，比如："We the People of United Status do ordain and establish this Consitution."
//如何只使用O（1）的额外空间，将他的词倒过来，即输出：
//Constitution. this establish amd ordain do Status United the of People the We
//难度 三星/五星


#include <iostream>
#include <string>
using namespace std;
//要求 只使用O（1）的额外空间 
int main() 
{
	char letter; 
	string sentence ="We the People of United Status do ordain and establish this Consitution.";
	 
    //Hint:分两步倒装，先把整个句子按字母倒装，再把每一个词倒装回来。
	// 先把整个句子按字母倒装
	
	//找到句子的中点，记住 4/2=2; 5/2=2; 在这个任务中，中间的字符倒置仍为它本身。 

	for ( int i=0; i<sentence.length()/2;i++){
		//cout<< sentence[i];
		//cout<<"\n";
		//一个简单的换位 
		letter=sentence[i];
		//cout<<letter;
		sentence[i]=sentence[sentence.length()-i-1];
		sentence[sentence.length()-i-1]=letter;
	}
	cout<<sentence; 
	cout<<"\n";
	//再把每一个词倒装回来。
	int end=-1;
	for (int i=0;i<sentence.length();i++){
		//先找空格
		if (sentence[i] == ' '){
			//find one word
			for(int j=end+1;j<=end+(i-end)/2;j++){
				letter=sentence[j];
				sentence[j]=sentence[end+i-j];
				sentence[end+i-j]=letter;
			}
			end=i; 
		}
	}
	//把最后一个词搞定 
	for(int j=end+1;j<=end+(sentence.length()-end)/2;j++){
			letter=sentence[j];
			sentence[j]=sentence[end+sentence.length()-j];
			sentence[end+sentence.length()-j]=letter;
		}
		cout<<sentence;
		return 0;
}
