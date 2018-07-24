#include <iostream>
using namespace std;

int main()
{
    int T,N;
    cin>>T;
    while(T--){
    	cin>>N;
    	int A[N][N];
    	for(int i = 0; i < N; i++){
    		for(int j = 0; j < N; j++){
    			cin>>A[i][j];
    		}
    	}
    	int B[N],C[N],i = 0, j = 0;
		for(int k = 0; k < N; k++){
			B[k] = A[i][j];
			j++;
		}
       j =  0;
		for(int k = 0; k < N; k++){
			C[k] = A[N-1-i][j];
			j++;
		}
		for(int i = 0; i < N; i++){
			cout<<B[i];
		}
       cout<<endl;
       for(int i = 0; i < N; i++){
			cout<<C[i];
		}

    }
    return 0;
}
