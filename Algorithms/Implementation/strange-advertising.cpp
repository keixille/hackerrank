#include <bits/stdc++.h>

using namespace std;

struct Advertisement {
    int shared;
    int liked;
    int cumulative;
    
    void init() {
        this->shared = -1;
        this->liked = -1;
        this->cumulative = -1;
    }
    
    void set(int prevShared, int prevCumulative) {
        this->shared = (prevShared/2)*3; 
        this->liked = this->shared/2;
        this->cumulative = prevCumulative + this->liked;
    }
};

Advertisement advertisement[51];
int advertisementCount = 1;

void initAdvertisement() {
    for(int i=1; i<=50; i++) {
        advertisement[i].init();
    }
}
void setAdvertisement(int start, int end) {
    for(int i=start; i<=end; i++) {
        advertisement[i].set(advertisement[i-1].shared, advertisement[i-1].cumulative);
        advertisementCount++;
    }
}

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
	initAdvertisement();
	advertisement[1].shared = 5;
	advertisement[1].liked = 2;
	advertisement[1].cumulative = 2;
	setAdvertisement(2, n);
    return advertisement[n].cumulative;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
