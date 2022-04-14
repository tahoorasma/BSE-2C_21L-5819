#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<fstream>
using namespace std;
int main()
{
	cout<<"\t\"WORD SEARCH PUZZLE\""<<'\n';
	cout<<"\t--------------------"<<endl;
	string ch;
	string inputWords[10];
	//reading the input file and printing the input words on console
	cout<<"The list of words in your file: "<<endl;
	ifstream fin("input1.txt",ios::in);
	for (int i=0; i<10; i++){
	fin>>ch;
	inputWords[i]=ch;
	cout<<inputWords[i];
	cout<<endl;}
	fin.close();
	cout<<"\nYour required grid: "<<endl;
	ofstream fout("output1.txt",ios::out);
	int randomNumber;
	char randomLetter;
	char outputPuzzle[10][10];
	//firstly initializing every letter in the word search puzzle with 'spaces'
	for (int i=0; i<10; i++){
	for (int j=0; j<10; j++){
	outputPuzzle[i][j]=' ';}}
	//inserting the input words randomly in different directions in the grid
	for (int word=0; word<10; word++){
	if (word==0){						//inserts vertically from up to down
	int row=3;
	int col=1;
	for (int i=0; inputWords[word][i]!='\0'; i++,row++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==1){					//inserts diagonally from top left to bottom right
	int row=1;
	int col=4;
	for (int i=0; inputWords[word][i]!='\0'; i++,row++,col++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==2){					//inserts vertically from up to down
	int row=1;
	int col=0;
	for (int i=0; inputWords[word][i]!='\0'; i++,row++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==3){					//inserts horizontally from left to right
	int row=9;
	int col=4;
	for (int i=0; inputWords[word][i]!='\0'; i++,col++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==4){					//inserts vertically from up to down
	int row=1;
	int col=9;
	for (int i=0; inputWords[word][i]!='\0'; i++,row++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==5){					//inserts horizontally from left to right
	int row=0;
	int col=1;
	for (int i=0; inputWords[word][i]!='\0'; i++,col++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==6){					//inserts vertically from down to up
	int row=8;
	int col=6;
	for (int i=0; inputWords[word][i]!='\0'; i++,row--){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==7){					//inserts vertically from down to up
	int row=9;
	int col=3;
	for (int i=0; inputWords[word][i]!='\0'; i++,row--){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==8){					//inserts diagonally from bottom left to top right
	int row=9;
	int col=0;
	for (int i=0; inputWords[word][i]!='\0'; i++,row--,col++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}
	else if (word==9){					//inserts diagonally from top left to bottom right
	int row=0;
	int col=0;
	for (int i=0; inputWords[word][i]!='\0'; i++,row++,col++){
	outputPuzzle[row][col]=inputWords[word][i];
	}}}
	/*alloting random letters to the left over 'spaces', generating
	output file and printing the grid on console and in the output file*/
	cout<<"-------------------"<<endl;
	for (int i=0; i<10; i++){
	for (int j=0; j<10; j++){
	if (outputPuzzle[i][j]==' '){
	randomNumber=rand()%26;
	randomLetter='a'+randomNumber;
	outputPuzzle[i][j]=randomLetter;}
	fout<<outputPuzzle[i][j]<<" ";
	cout<<outputPuzzle[i][j]<<" ";}
	fout<<endl;
	cout<<endl;}
	cout<<"-------------------"<<endl;
	fout.close();
	return 0;
}
