#include <string>

struct Specialization
{
	explicit Specialization(const std::string& str) : spec(str) {}
	std::string spec;
};

struct Course
{
	explicit Course(const std::string& str) : course(str) {}
	std::string course;
};

struct Week
{
	explicit Week(const std::string& str) : week(str) {}
	std::string week;
};

struct LectureTitle
{
	explicit LectureTitle(const Specialization& spec, const Course& course, const Week& week)
		: specialization(spec.spec), course(course.course), week(week.week) {}
	
	std::string specialization;
	std::string course;
	std::string week;
};
