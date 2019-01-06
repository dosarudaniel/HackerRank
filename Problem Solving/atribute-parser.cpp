#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Tag {
  struct Tag* parent;
  vector<struct Tag*> kids;

  string tagname;
  // name -> value
  unordered_map<string, string> properties;
};

// Just for debugging
int level = 0;
void printTree(Tag *node) {
  cout << string(level, '-') << node->tagname << endl;
  level++;
  for (int i = 0; i < node->kids.size(); i++) {
    printTree(node->kids[i]);
  }
  level--;
}

int main() {
  int Q, N;
  cin >> N >> Q;
  vector<string> code(N, "");
  vector<string> query(Q, "");

  vector<Tag *> primary_tags;
  unordered_map<string, Tag *> all_tags;
  // tagname <-> Tag*
  Tag *lastTag = NULL;

  getline(cin, code[0]);
  for (int i = 0; i < N; i++) {
    getline(cin, code[i]);
    if (code[i][1] != '/') { // tag open
      Tag *t = new Tag;
      t->parent = lastTag;
      int n = code[i].length();
      vector<string> words;
      string word;
      stringstream s(code[i].substr(1, n - 2));
      while (s >> word) {
        words.push_back(word);
      }

      string tagname = words[0];
      t->tagname = tagname;
      if (words.size() > 1) {
        for (int j = 1; j < words.size() - 2; j++) {
          pair<string, string> p(
              words[j], words[j + 2].substr(1, words[j + 2].length() - 2));
          t->properties.insert(p);
        }
      }
     
      lastTag = t;
      if (t->parent == NULL) {
        primary_tags.push_back(t);
      } else {
        // Add this tag to his parent's kids
        t->parent->kids.push_back(t);
        //cout << "Add " << t->tagname << " to " << t->parent->tagname << "'s kids." << endl;
      }
      pair<string, Tag*> p(tagname, t);
      all_tags.insert(p);

    } else { // tag close
      lastTag = lastTag->parent;
    }
  }

  // Parse queries
  for (int i = 0; i < Q; i++) {
    getline(cin, query[i]);
    string tagname, name;
    string query_copy = query[i];

    vector<string> tagnames;
    while (query_copy.size() > 0) {
      int point = query_copy.find_first_of('.');
      if (point == -1) {
        int tilda = query_copy.find_last_of('~');
        tagname = query_copy.substr(0, tilda);
        tagnames.push_back(tagname);
        name = query_copy.substr(tilda+1, query_copy.length()-1);
        query_copy = "";
      } else {
        tagname = query_copy.substr(0, point);
        tagnames.push_back(tagname);
        query_copy = query_copy.substr(point+1);
      }
    }

    Tag* node;
    unordered_map<string, Tag *>::const_iterator got =
        all_tags.find(tagnames[tagnames.size()-1]);
    if (got == all_tags.end()) {
      cout << "Not Found!\n";
    } else {
      node = got->second;
      unordered_map<string, string>::const_iterator it = node->properties.find(name);
      if (it == node->properties.end()) {
        cout << "Not Found!\n";
      } else {
        bool flag = true;
        int j = tagnames.size() - 1;
        // check parents
        while (node->parent != NULL) {
          if (j == 0) {
            flag = false;
            cout << "Not Found!\n";
            break;
          }

          if (node->parent->tagname != tagnames[j-1]) {
            flag = false;
            cout << "Not Found!\n";
            break;
          }
          j--;
          node = node->parent;
        }

        if (flag) {
          cout << it->second << endl;
        }
      }
    }
  }

  return 0;
}

