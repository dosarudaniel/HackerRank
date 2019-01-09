#include<bits/stdc++.h>

using namespace std;

struct Workshop {
  int start_time;
  int end_time;
  int duration;
};

struct Available_Workshops {
  vector<Workshop> workshops;
};

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

Available_Workshops* initialize(int start_time[], int duration[], int n) {
  Available_Workshops* aworkshops = new Available_Workshops;
  
  for (int i = 0; i < n; i++) {
    Workshop w;
    w.start_time = start_time[i];
    w.duration = duration[i];
    w.end_time = start_time[i] + duration[i];
    aworkshops->workshops.push_back(w);
  }
  return aworkshops;
}

bool Compare(Workshop w1, Workshop w2) {
  if (w1.end_time == w2.end_time) {
    return w1.duration < w2.duration;
  } else {
    return w1.end_time < w2.end_time;
  }
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
  sort(ptr->workshops.begin(), ptr->workshops.end(), Compare);

  int n = ptr->workshops.size();
  int nr = 1;
  int j = 0;
  for (int i = 1; i < n; i++) {
    if (ptr->workshops[i].start_time >= ptr->workshops[j].end_time) {
      j = i;
      nr++;
    }
  }
  return nr;
}

int main(int argc, char *argv[]) {
