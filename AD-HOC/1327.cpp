#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <string.h>

using namespace std;

struct player {
	char name[25];
	int id;	
};

struct cmp {
	bool operator() (const struct player& lhs, const struct player& rhs) const {
        return lhs.id < rhs.id;
    }
};

int N;
struct player players[25];
set<struct player, struct cmp> alive;
queue<int> deck;
vector<int> remove_;
int min_, v;
vector<int> last_removed;

void clear_queue(queue<int> & q) {
	queue<int> empty_;
	empty_.swap(q);
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		clear_queue(deck);
		alive.clear();
		for (int i = 0; i < N; i++) {
			scanf(" %s ", players[i].name);
			players[i].id = i;
			alive.insert(players[i]);			
		}
		for (int i = 0; i < 52; i++) {
			scanf("%d ", &v);
			deck.push(v);
		}
		while (1) {
			min_ = 20;
			remove_.clear();
			for (auto it = alive.begin(); it != alive.end(); ++it) {
				if (deck.empty()) {
					goto EMPTY_DECK;
				}
				if (deck.front() < min_) {
					remove_.clear();
					remove_.push_back(it->id);
					min_ = deck.front();
				} else if (min_ == deck.front()) {
					remove_.push_back(it->id);
				}
				deck.pop();
			}
			if (remove_.size() == alive.size()) {
				break;
			}
			for (int i = 0; i < remove_.size(); i++) {
				alive.erase(players[remove_[i]]);
			}
		}
		if (0) {
			EMPTY_DECK:
			remove_.clear();
			for (auto it = alive.begin(); it != alive.end(); ++it) {
				remove_.push_back(it->id);
			}
		}
		for (int i = 0; i < remove_.size(); i++) {
			printf("%s ", players[remove_[i]].name);
		}
		printf("\n");
	}

	return 0;
}