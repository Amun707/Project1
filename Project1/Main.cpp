#include <iostream>
#include <string>
//��������� ������

class DinamicArray {
public:
	DinamicArray() :data_(nullptr), size_(0){}//����������� �� ���������
	DinamicArray(const DinamicArray& other) {//����������� �����������
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; i++)//��������� ������ ������� ������ ����
			data_[i] = other.data_[i];
	}
	DinamicArray(DinamicArray&& other) {//����������� ��������
		//,&& - ����������� ������ �� ��������� ������,
		// ������� �������� ���� �����
		this->size_ = 0;
		this->data_ = nullptr;
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
}

	~DinamicArray() {//����������, �������� �������
		//��� ���-�� ���� � ������� ���
		if (data_)//���� � ���� data_ ��� �� ����
			delete[]data_;
}
	void AddBack(float value) {//����� ����������
		if (data_) {//���� � ���� data_ ��� �� ����(��������� ���������), ���� ��� ���-�� ���������
			//�.�. �������� �� ���� ������� ������ ��� � ��� ����
			auto tmp = new float[size_ + 1];//auto - ���������������, ���������� ��� ������ ������ �� auto
			for (size_t i = 0; i < size_; i++)
				tmp[i] = data_[i];
			tmp[size_] = value;//�� ��������� ����� ������� ��������� value
			std::swap(tmp, data_);//������ ������� �������
			size_ += 1;
			delete[]tmp;//����������� �������� ������
		}
		else {//���� � ���� data_ ������ ���
			data_ = new float[1] {value};
			size_ += 1;
	}
	}
	void PopBack() {//����� �������� � ����� ���������
		if (data_) {//���� � ���� data_ ��� �� ����(��������� ���������)
			auto tmp = new float[size_ - 1];
			for (size_t i = 0; i < size_-1; i++)
				tmp[i] = data_[i];
			std::swap(tmp, data_);//������ ������� �������
			size_ -= 1;//��������� ������ �������
			delete[]tmp;//����������� �������� ������
			if (size_ == 0) {//���� � ������� ������ ���
				delete[]data_;//����� �� ������� ��� ��� ��� ��� �������� "������"
				data_ = nullptr;//���� data_ �� ������� ��������� �� � ���������� delete[]- ��������� �����
			}
		}
	}
	float& operator[](int n) {//��������� � �������� ������� ������ ������
		return data_[n];
	}
	const float& operator[](int n)const {
		return data_[n];
	}
	DinamicArray& operator = (const DinamicArray& other) {
		if (data_) {
			delete[]data_;
		}
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; ++i) {
			data_[i] = other.data_[i];
		}
		return *this;
	}

	DinamicArray& operator = (DinamicArray&& other) {
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
		return *this;
	}

private:
	float* data_;
	int size_;
	//int capacity; - ��������� ��� ����� �������, �� ���������� ������ � ���������� �������
};

void F00(DinamicArray obj){}


int main() {
	system("chcp 1251>nul");

	int* p = new int[10];
	std::cout << p[8];
	float arr[123];
	DinamicArray arrd;
	arrd.AddBack(1234.5);
	std::cout << arrd[0];
	F00(arrd);
	arrd.PopBack();
	DinamicArray arrd2;
	arrd2 = arrd;






	return 0;
}