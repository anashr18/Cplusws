#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results);
void updateScores(string team, int points, unordered_map<string, int> &scores);

int main(){
    vector<vector<string>> competitions = {
          {"HTML", "C#"}, {"C#", "Python"}, {"Python", "HTML"}};
    vector<int> results = {0, 0, 1};
    string output = tournamentWinner(competitions, results);

    cout << output << endl;
    return 0;
}

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  // Write your code here.
    const int HOME_TEAM_WON = 1;
    string currentBestTeam = "";
    unordered_map<string, int> scores = {{currentBestTeam, 0}}; 
    int idx = 0;
    while(idx< results.size()){
        auto competition = competitions[idx];
        auto homeTeam = competition[0];
        auto awayTeam = competition[1];
        auto result = results[idx];
        auto winnerTeam = result==HOME_TEAM_WON? homeTeam:awayTeam;
        // cout << winnerTeam;
        updateScores(winnerTeam, 3, scores);
        if (scores[winnerTeam] > scores[currentBestTeam]){
            // cout << winnerTeam;
            currentBestTeam = winnerTeam;
        }
        idx++;
    }
    return currentBestTeam;
}

void updateScores(string team, int points, unordered_map<string, int> &scores){
     if (scores.find(team) == scores.end()){
            scores[team] = 0;
        }
        scores[team] +=3;
}
