#include <iostream>
#include <vector>
using namespace std;

const int MAX_NAME_SIZE = 24;

struct Highscore {
    char name[MAX_NAME_SIZE];
    int score;
};

void getVectorSize(int& size);
void readData(vector<Highscore>& scores);
void sortData(vector<Highscore>& scores);
vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation);
void displayData(const vector<Highscore>& scores);

int main()
{
    int size;
    getVectorSize(size);

    vector<Highscore> highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);

    return 0; 
}





void getVectorSize(int& size) {
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}





void readData(vector<Highscore>& scores)
{
    vector<Highscore>::iterator scoresit;
    for (scoresit = scores.begin(); scoresit != scores.end(); ++scoresit)
    {
        cout << "Enter the name for score #" << (scoresit - scores.begin()) + 1 << ": ";
        cin.getline(scoresit -> name, MAX_NAME_SIZE);

        cout << "Enter the score for score #" << (scoresit - scores.begin()) + 1 << ": ";
        cin >> scoresit->score;
        cin.ignore();
    }
}





void sortData(vector<Highscore>& scores) {
    for (vector<Highscore>::iterator scoresit = scores.begin(); scoresit != scores.end() - 1; ++scoresit) {
        vector<Highscore>::iterator LargestIt = findLocationOfLargest(scoresit, scores.end());
        swap(*LargestIt, *scoresit);

    }
}





vector<Highscore>::iterator findLocationOfLargest(const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation) {
    vector<Highscore>::iterator LargestIt = startingLocation;

    for (vector<Highscore>::iterator it = startingLocation + 1 ; it != endingLocation; ++it) {
        if (it->score > LargestIt->score) {
            LargestIt = it;
        }
    }
    return LargestIt;
}










void displayData(const vector<Highscore>& scores)
{
    cout << "Top Scorers: " << endl;
    for (auto scoresit = scores.begin(); scoresit != scores.end(); ++scoresit)
    {
        cout << scoresit->name << ": " << scoresit->score << endl;
    }
}

