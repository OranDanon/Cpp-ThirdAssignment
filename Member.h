#ifndef Member_H
#define Member_H
#include <iostream>
#include <map>
#include <iterator>
using namespace std;

class Member
{
private:

	static size_t counter;
	struct cmpByID
	{
		bool operator()(const size_t a, const size_t b) const
		{
			return a < b;
		}
	};
	size_t m_id;
	map<size_t,Member*, cmpByID> m_followedBy;
	map<size_t,Member*, cmpByID> m_follow;

public:
	/**
	* C'tor of Member
	**/
	Member();


	/**
	* Check if ids are equals
	*/
	inline bool operator==(const Member& other) const;

	/**
	* Destructor of Member
	**/
	~Member();

	/**
	* add member to following set
	**/
	void follow(Member& mem);
	/**
	* Remove member from the set
	**/
	void unfollow(Member& member);

	/**
	* Return the number of followers
	**/
	int numFollowers();

	/**
	* Return the number of following
	**/
	int numFollowing();
	/**
	* Return the number of members
	**/
	int static count();
};

#endif // Member_H