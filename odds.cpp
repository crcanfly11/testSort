#include <boost\bind.hpp>

#include <iostream>  
#include <vector>
#include <map>
#include <algorithm>

using namespace std;  
  
void printVT(int value, vector<int>& vt)
{
	cout<<"value:" <<value <<endl;
};

void mprint(int frontV, int value)
{
	cout<<" " <<frontV <<"*" <<value <<" " <<endl;
};

vector<int>::iterator calculate(vector<int>::iterator ibegin, vector<int>::iterator iend)
{
	//º”Ω· ¯≈–∂œ
	if(ibegin == iend) return ibegin;
	
	for_each(ibegin, iend, boost::bind(&mprint, *ibegin, _1));

	++ibegin;
	return calculate(ibegin, iend);
};

void main()
{
	vector<int> vt;
	
	for(int i=0;i<10;i++) {
		vt.push_back(i+1);
	}
	
	for_each(vt.begin(), vt.end(),boost::bind(&printVT,_1,boost::ref(vt)));

	calculate(vt.begin(),vt.end());

	std::system("pause");

};

//class fixtures_base_odds
//{
//	enum team_odd_enum { home_team_win = 0, shake_hands = 1, away_team_win = 2 };
//
//	double team_odds_[3];
//
//	char home_team_[30];
//	char away_team_[30];
//public:
//	fixtures_base_odds(double win_odds, double shake_hands_odds, double lose_odds, const char* home_team_name, const char* away_team_name) 
//	{
//		team_odds_[home_team_win] = win_odds;
//		team_odds_[shake_hands] = shake_hands_odds;
//		team_odds_[away_team_win] = lose_odds;
//
//		std::strcpy(home_team_, home_team_name);
//		std::strcpy(away_team_, away_team_name);
//	};
//
//	double get_win_odds() const { return team_odds_[home_team_win]; }
//	double get_shake_hands_odds() const { return team_odds_[shake_hands]; }
//	double get_lose_odds() const { return team_odds_[away_team_win]; }
//};
//
//class forecas_result
//{
//	float odds_;
//	unsigned short multiple_;
//	float yield_;			     //Unit of Measure %
//	char result_msg_[50]; 
//
//public:
//	forecas_result(float odds, const char* result_msg) : odds_(odds)
//	{
//		std::strcpy(result_msg_, result_msg);
//		yield_ = (odds - 1)*100;
//	}
//
//	void set_result_multiple(unsigned short multiple) { multiple_ = multiple; }
//
//	unsigned short get_result_multiple() const { return multiple_; }
//	float get_result_yield() const { return yield_; }
//	const char* get_result_msg() const { return result_msg_; }
//};
//
//void resultset(fixtures_base_odds odd)
//{
//
//};
//
//int main(int argc, char* argv[])  
//{  
//	double htwin,sh,atwin;
//	char htname[20],atname[20];
//	char tmp[100];
//
//	typedef vector<fixtures_base_odds> base_odds_vector;
//	base_odds_vector base_odds;
//
//	typedef map<unsigned short, forecas_result> forecas_result_map;
//	forecas_result_map forecas_results;
//
//	while(1) {
//		cout<<"add new fixtures odds?(Y:yes/others:no)"<<endl;
//		cin.getline(tmp,100);
//		cin.clear();
//
//		if(!strcmp(tmp,"Y")||!strcmp(tmp,"y")) {
//			cout<<"input home team win odds:"<< endl;
//			cin.getline(tmp,100);
//			htwin = atof(tmp);
//			cin.clear();
//
//			cout<<"input shake hands odds:"<< endl;
//			cin.getline(tmp,100);
//			sh = atof(tmp); 
//			cin.clear();
//
//			cout<<"input away team win odds:"<< endl;
//			cin.getline(tmp,100);
//			atwin = atof(tmp); 
//			cin.clear();
//
//			cout<<"input away team win odds:"<< endl;
//			cin>>htname;
//			cin.clear();
//
//			cout<<"input away team win odds:"<< endl;
//			cin>>atname;
//			cin.clear();
//
//			fixtures_base_odds* pbo = new fixtures_base_odds(htwin, sh, atwin, htname, atname);
//			base_odds.push_back(*pbo);
//		}else {
//			break;
//		}
//	}
//
//	for_each(base_odds.begin(), base_odds.end(),&resultset);
//};