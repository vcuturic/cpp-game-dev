/*
Introductrion to classes, initializer lists, const correctness
Basic optimization tactics, vectors etc.
*/

#include <iostream>
#include <vector>
#include <fstream>

//using namespace std;

class Student 
{
	std::string		m_first =	"First";
	std::string		m_last =	"Last";
	int				m_id =		0;
	float			m_avg =		0;

public:

	Student() {}

	Student(std::string first, std::string last, int id, float avg) 
		: m_first	(first)
		, m_last	(last)
		, m_id		(id)
		, m_avg		(avg)
	{
	}

	float getAvg() const
	{
		return m_avg;
	}

	int getId() const
	{
		return m_id;
	}

	std::string getFirst() const
	{
		return m_first;
	}

	std::string getLast() const
	{
		return m_last;
	}

	void print() const {
		std::cout << m_first << " " << m_last << " ";
		std::cout << m_id << " " << m_avg << std::endl;
	}

	/*const correctness - use const whenever function does not change parameters*/
};

class Course {
	std::string m_name = "Course";
	std::vector<Student> m_students;
	
public:
	Course() {}

	Course(std::string name)
		:m_name(name)
	{
	}

	// & so the function does not copy Student, we pass the reference. 
	// const so it does not change it
	void addStudent(const Student& s)
	{
		m_students.push_back(s);
	}

	// c++ is passed by value - it copies the return of the function (slower)
	// & so it returns the list directly
	// const on the end - the function will not change list of students
	// const on start - whatever we are returning - CANNOT be CHANGED
	const std::vector<Student>& getStudents() const
	{
		return m_students;
	}

	std::string getName()
	{
		return m_name;
	}

	void loadFromFile(const std::string& fileName)
	{
		std::ifstream fileInputStream(fileName);
		std::string first;
		std::string last;
		int id;
		float avg;

		// it reads a string token - list of chars interrupted by new lines or whitespace
		while (fileInputStream >> first) {
			fileInputStream >> last >> id >> avg;

			addStudent(Student(first, last, id, avg));
		}
	}

	void print() const {
		for(auto& stud : m_students)
		{
			stud.print();
		}
	}
};

int main(int argc, char * argv[]) {

	Course course("Course1");
	course.loadFromFile("students.txt");
	course.print();

	/*Student s1;
	Student s2("John", "Doe", 1, 3.14);
	Student s3("Jane", "Doe", 20260001, 8.45);

	Course course("Course1");
	course.addStudent(s1);
	course.addStudent(s2);
	course.addStudent(s3);

	course.print();*/
	//std::vector<int> vec;
	// 
	//vec.push_back(10);
	//vec.push_back(42);

	//for (size_t i = 0; i < vec.size(); i++)
	//{
	//	std::cout << vec[i] << std::endl;
	//}

	//// copies stuff - slower with long strings or other data structures
	//for (auto a : vec)
	//{
	//	std::cout << a << std::endl;
	//}

	// can use &, to do it right in memory.
	/*for (auto& a : vec)
	{
		std::cout << a << std::endl;
	}*/

	/*std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;*/

	return 0;
}