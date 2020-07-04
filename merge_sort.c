#include <stdio.h>
#define max (7)
//mergesort의 경우 설명할 때, 간단히 인덱스 분할을 끝낸 후, 정렬을 한다고 설명하지만 알고리즘을 살펴보면 스택구조에 의해 인덱스 분할과 정렬을 동시에 진행함.

//분할정복법
//분할. low 와 high의 중간 mid를 찾습니다. 이진 검색에서 중간점을 찾았던 것과 같은 방법으로 2로 나누어 정수로 값 리턴.이를 활용해 배열을 앞뒤로 2개로 분할함. 
//정복. 분할 단계에서 만들어진 두 하위 배열에 각각에 있는 하위 배열을 재귀적으로 정렬.
//결합. 정렬된 두 하위 배열을 하나의 정렬된 배열로 결합.

void merge(int a[], int low, int mid, int high){
	int b[1000];
	int i=low;
	int j=mid+1;
	int k=0;

	while(i <= mid && j<= high){	//왼쪽 배열의 첫 값과 오른쪽 배열의 첫 값을 비교함.이후 증가된 i, k값에 따라 반복
		if(a[i]<=a[j]){				//왼쪽 배열의 첫 값이 더 작으면, 왼쪽 배열의 첫 값을 배열 b에 저장하고 i 및 k값 증가
			b[k] = a[i];
			i++;
		}
		else{						//오른쪽 배열의 첫 값이 더 작으면, 오른쪽 배열의 첫 값을 배열 b에 저장하고 i 및 k값 증가
			b[k] = a[j];
			j++;
		}
		k++;
	}

	while(i<=mid){	//왼쪽이 남아있다면 남은 값 전달
		b[k] = a[i];
		k++;
		i++;
	}

	while(j<=high){	//오른쪽이 남아있다면 남은 값 전달
		b[k] = a[j];
		j++;
		k++;
	}

	k--; 	//k가 마지막에도 1 더해져 index값이 배열의 크기를 벗어나므로 1빼줌.

	while(k>=0){	//k를 하나씩 줄여가며 원래 arr인 a에 전달.
		a[low+k]=b[k];
		k--;
	}
}

void mergesort(int a[], int low, int high){
	if(low<high){	//재귀함수의 탈출조건 if,else문
		int m = (low+high)/2;	//중간값 계산

		mergesort(a,low,m);		//중간값을 이용해 분할

		mergesort(a,m+1,high);	//가장 왼쪽 인덱스 분할이 끝난 후, 차례대로 스택구조에 의해 호출된다. 
	
		merge(a,low,m,high);	
	}
	else{
		return;
	}
}

int main(){
	int a[max] = {20,10,70,80,40,90,30};
	int i = 0;
	printf("Before:\n");
	for(i=0; i<max; i++){
		printf("%d ",a[i]);
	}
	mergesort(a,0,max-1);

	printf("\nAfter:\n");
	for(i=0; i<max; i++){
		printf("%d ",a[i]);
	}
}
