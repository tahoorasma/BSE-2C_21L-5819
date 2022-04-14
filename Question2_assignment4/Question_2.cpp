#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<fstream>
using namespace std;
int  startingRowIndex, startingColIndex, endingRowIndex, endingColIndex;
bool searchHorizontallyLeftToRight(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";		//copies all letters of wordToSearch to make sure the word that is found is present in the grid or not
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (row=0; row<18; row++){
	for (col=0; col<19; col++){
	//firstly searching for the first letter of the word to be searched
	if (wordToSearch[0]==grid[row][col]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	col++;
	endingColIndex=startingColIndex;
	//now searching for the remaining letters of the word to be searched
	for (int i=1; wordToSearch[i]!='\0'; i++,col++){
	if (wordToSearch[i]!=grid[row][col]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingColIndex++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	endingRowIndex=startingRowIndex;
	//tallying the wordToSearch and WordFound if the word that was to be searched is found or not
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
bool searchHorizontallyRightToLeft(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (row=0; row<18; row++){
	for (col=18; col>=0; col--){
	if (wordToSearch[0]==grid[row][col]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	col--;
	endingColIndex=startingColIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++,col--){
	if (wordToSearch[i]!=grid[row][col]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingColIndex--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	endingRowIndex=startingRowIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
bool searchVerticallydown(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (col=0; col<19; col++){
	for (row=0; row<18; row++){
	if (wordToSearch[0]==grid[row][col]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	row++;
	endingRowIndex=startingRowIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++,row++){
	if (wordToSearch[i]!=grid[row][col]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingRowIndex++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	endingColIndex=startingColIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
bool searchVerticallyup(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (col=0; col<19; col++){
	for (row=17; row>=0; row--){
	if (wordToSearch[0]==grid[row][col]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	row--;
	endingRowIndex=startingRowIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++,row--){
	if (wordToSearch[i]!=grid[row][col]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingRowIndex--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	endingColIndex=startingColIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
bool searchDiagonallyTopLeftToBottomRight(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (col=0; col<19; col++){
	for (row=0; row<18; row++){
	int r=row;
	int c=col;
	if (wordToSearch[0]==grid[r][c]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	r++;
	c++;
	endingRowIndex=startingRowIndex;
	endingColIndex=startingColIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++,r++,c++){
	if (wordToSearch[i]!=grid[r][c]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingRowIndex++;
	endingColIndex++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
bool searchDiagonallyBottomRightToTopLeft(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (col=18; col>=0; col--){
	for (row=17; row>=0; row--){
	int r=row;
	int c=col;
	if (wordToSearch[0]==grid[r][c]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	r--;
	c--;
	endingRowIndex=startingRowIndex;
	endingColIndex=startingColIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++,r--,c--){
	if (wordToSearch[i]!=grid[r][c]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingRowIndex--;
	endingColIndex--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
bool searchDiagonallyTopRightToBottomLeft(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (col=18; col>=0; col--){
	for (row=0; row<18; row++){
	int r=row;
	int c=col;
	if (wordToSearch[0]==grid[r][c]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	r++;
	c--;
	endingRowIndex=startingRowIndex;
	endingColIndex=startingColIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++,r++,c--){
	if (wordToSearch[i]!=grid[r][c]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingRowIndex++;
	endingColIndex--;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
bool searchDiagonallyBottomLeftToTopRight(char grid[18][19], char wordToSearch[])
{
	char wordFound[20]=" ";
	bool firstIndexFound=false, found=false;
	int row, col;
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	for (col=0; col<19; col++){
	for (row=17; row>=0; row--){
	int r=row;
	int c=col;
	if (wordToSearch[0]==grid[r][c]){
	firstIndexFound=true;
	wordFound[0]=wordToSearch[0];
	startingRowIndex=row, startingColIndex=col;
	r--;
	c++;
	endingRowIndex=startingRowIndex;
	endingColIndex=startingColIndex;
	for (int i=1; wordToSearch[i]!='\0'; i++,r--,c++){
	if (wordToSearch[i]!=grid[r][c]){
	firstIndexFound=false;
	found=false;
	break;}
	else{
	wordFound[i]=wordToSearch[i];
	endingRowIndex--;
	endingColIndex++;}
	found=true;}
	}
	if (found)
	break;}
	if (found)
	break;}
	for (int i=1; wordToSearch[i]!='\0'; i++){
	if (wordFound[i]!=wordToSearch[i]){
	startingRowIndex=0, startingColIndex=0, endingRowIndex=0, endingColIndex=0;
	break;}}
	if (startingRowIndex==0 && startingColIndex==0 && endingRowIndex==0 && endingColIndex==0)
	return false;
	else
	return true;
}
int main()
{
	cout<<"\t    \"WORD SEARCH\""<<'\n';
	cout<<"\t    -------------"<<endl;
	char ch;
	char grid[18][19];
	ifstream fin("input2.txt",ios::in);
	ofstream fout("output2.txt",ios::out);
	//reading the input file and printing grid on console
	for (int i=0; i<18; i++){
	for (int j=0; j<19; j++){
	fin>>ch;
	grid[i][j]=ch;
	cout<<ch<<" ";}
	cout<<endl;}
	fin.close();
	cout<<"\n*INSTRUCTIONS: Enter 0 to End Game";
	char wordToSearch[20]=" ";
	while(!0){
	bool input=false;
	while (!input){
	cout<<"\nEnter: ";
	cin>>wordToSearch;
	cin.ignore();
	if (wordToSearch[0]=='0')
	system("pause");
	for (int i=0; wordToSearch[i]!='\0'; i++){
	//checking if the user entered a wrong input
	if (!(wordToSearch[i]>=97 && wordToSearch[i]<=122) && !(wordToSearch[i]>=65 && wordToSearch[i]<=90)){
	cout<<"Wrong Input. Pls input a WORD again";
	input=false;
	break;}
	else
	input=true;}}
	//converting lowercase letters entered by user to uppercase
	for (int i=0; wordToSearch[i]!='\0'; i++){
	if (wordToSearch[i]>=97 && wordToSearch[i]<=122){
	wordToSearch[i]=wordToSearch[i]-32;}}
	/*generating the output file and printing the words to be searched and
	their starting and ending indicis on the console and in the output file*/
	cout<<"seaching for "<<wordToSearch<<endl;
	fout<<"Entered word: "<<wordToSearch<<"\nIndices: ";
	if (searchHorizontallyLeftToRight(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else if (searchHorizontallyRightToLeft(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else if (searchVerticallydown(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else if (searchVerticallyup(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else if (searchDiagonallyTopLeftToBottomRight(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else if (searchDiagonallyBottomRightToTopLeft(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else if (searchDiagonallyTopRightToBottomLeft(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else if (searchDiagonallyBottomLeftToTopRight(grid, wordToSearch)){
	cout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;
	fout<<"("<<startingRowIndex<<","<<startingColIndex<<")"<<"("<<endingRowIndex<<","<<endingColIndex<<")"<<endl;}
	else{
	cout<<"Word not found!"<<endl;
	fout<<"Word not found!"<<endl;}}
	fout.close();
	return 0;		 
}

