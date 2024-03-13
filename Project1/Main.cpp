#include <iostream>
#include <string>
//коллекции данных

class DinamicArray {
public:
	DinamicArray() :data_(nullptr), size_(0){}//конструктор по умолчанию
	DinamicArray(const DinamicArray& other) {//конструктор копирования
		size_ = other.size_;
		data_ = new float[size_];
		for (int i = 0; i < size_; i++)//переносим данные другого класса себе
			data_[i] = other.data_[i];
	}
	DinamicArray(DinamicArray&& other) {//конструктор переноса
		//,&& - специальная ссылка на временный объект,
		// имеющий короткий срок жизни
		this->size_ = 0;
		this->data_ = nullptr;
		std::swap(data_, other.data_);
		std::swap(size_, other.size_);
}

	~DinamicArray() {//Деструктор, котоорый смотрит
		//что что-то есть и удаляет это
		if (data_)//если в поле data_ что то есть
			delete[]data_;
}
	void AddBack(float value) {//метод добавления
		if (data_) {//если в поле data_ что то есть(ненулевой указатель), надо это где-то сохранить
			//т.е. выделить на один элемент больше чем у нас есть
			auto tmp = new float[size_ + 1];//auto - самоопределение, возвращает тип данных справа от auto
			for (size_t i = 0; i < size_; i++)
				tmp[i] = data_[i];
			tmp[size_] = value;//на последнем месте массива размещаем value
			std::swap(tmp, data_);//меняем местами массивы
			size_ += 1;
			delete[]tmp;//освобождаем ненужную память
		}
		else {//если в поле data_ ничего нет
			data_ = new float[1] {value};
			size_ += 1;
	}
	}
	void PopBack() {//метод удаления с конца коллекции
		if (data_) {//если в поле data_ что то есть(ненулевой указатель)
			auto tmp = new float[size_ - 1];
			for (size_t i = 0; i < size_-1; i++)
				tmp[i] = data_[i];
			std::swap(tmp, data_);//меняем местами массивы
			size_ -= 1;//уменьшаем размер массива
			delete[]tmp;//освобождаем ненужную память
			if (size_ == 0) {//если в массиве ничего нет
				delete[]data_;//чтобы ОС помнила что она под нас выделила "ничего"
				data_ = nullptr;//поле data_ на нулевой указатель тк в результате delete[]- муссорный адрес
			}
		}
	}
	float& operator[](int n) {//Обращение к элементу массива нашего класса
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
	//int capacity; - требуется для более сложной, но эфективной работы с выделенной памятью
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