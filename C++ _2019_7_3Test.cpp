1.�ַ������ҳ�����������ִ�
**��Ŀ����**
�ַ������ҳ�����������ִ� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K
����һ���ַ���str������ַ���str�е�����������ִ� .

**��������**
�����������1������������һ���ַ���str�����Ȳ�����255�� 

**�������**
��һ�������str��������������ִ���

ʾ��1 : ���� abcd12345ed125ss123456789
		��� 123456789

**����˼·**
�����ַ�����ʹ��curȥ��¼���������ִ�������������������ַ������ʾһ��
���������ִ������ˣ��� ���ִ���֮ǰ�����ִ��Ƚϣ��������������¸���
�����ִ����µ�res.

**�������**

#include<iostream>
#include<string> 
	  using namespace std;
int main(){
	string str, res, cur;
	cin >> str;
	for (int i = 0; i <= str.length(); i++){
		// ����+=��cur        
		if (str[i] >= '0' && str[i] <= '9'){
			cur += str[i];
		}
		else{
			// �ҳ��������ַ�����������ַ���            
			if (res.size() < cur.size()){
				res = cur;
			}
			else{
				cur.clear();
			}
		}
	}
	cout << res;
	return 0;
}

2.�����г��ִ�������һ�������
**��Ŀ����**
�����г��ִ�������һ������� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | 
�������ƣ�[Javascript_V8, Python, C++, Javascript, Php, C#, Java]
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������
һ������Ϊ9������{ 1, 2, 3, 2, 2, 2, 5, 4, 2 }����������2�������г���
��5�Σ��������鳤�ȵ�һ�룬������2���������������� 0��

**��Ŀ����**
��������ܼ򵥣���Ҫ�ҳ�����һ����Ǹ����֡�

**����˼·**

**˼·һ**
���������������������������ڣ���һ���������м��Ǹ��������ַ�����Ȼ
������⣬������ �漰������sort����ʱ�临�Ӷ�ΪO(NlogN)�������ţ�

**�ⷨһ**

class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������        
		if (numbers.empty()){
			return 0;
		}
		sort(numbers.begin(), numbers.end());
		// ����ȡ�����м��Ǹ���        
		int middle = numbers[numbers.size() / 2];
		int count = 0;
		// ���ִ���        
		for (int i = 0; i<numbers.size(); ++i){
			if (numbers[i] == middle){
				++count;
			}
		}
		return (count>numbers.size() / 2) ? middle : 0;
	}
};

**����˼·2**
����з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ
�ڱ�������ʱ��������ֵ�� һ��������һ�����֣�һ�Ǵ�����������һ����
��ʱ��������֮ǰ�����������ͬ���������1����������� 1��������Ϊ0��
�򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����
Ȼ�����ж��� �Ƿ������������.

**�ⷨ��**

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		if (numbers.empty()){
			return 0;
		}
		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1         
		int result = numbers[0];
		int times = 1; // ����                 
		for (int i = 1; i<numbers.size(); ++i){
			if (times == 0){
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1                
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result){
				// ��ͬ���1
				++times;
			}
			else
			{
				// ��ͬ���1
				--times;
			}
		}
		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��        
		times = 0;
		for (int i = 0; i<numbers.size(); ++i){
			if (numbers[i] == result){
				++times;
			}
		}
		return (times > numbers.size() / 2) ? result : 0;
	}
};
