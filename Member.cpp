#include "Member.h"
using namespace std;

size_t Member::counter = 0;

inline bool Member::operator==(const Member& other) const
{
	if (this->m_id == other.m_id)
		return true;
	return false;
}


Member::Member() :m_id(counter++)// Warning overflows
{
}

Member::~Member()
{
	for (auto it = m_followedBy.begin(); it != m_followedBy.end(); ++it)
	{
		it->second->m_follow.erase(this->m_id);
	}
	for (auto it = m_follow.begin(); it != m_follow.end(); ++it)
	{
		it->second->m_followedBy.erase(this->m_id);
	}
	counter--;
}

void Member::follow(Member& mem) 
{
	//Maps have unique keys!
	if (m_follow.find(mem.m_id) == m_follow.end()) // Means not found mem.m_id
	{
		auto r_value = m_follow.insert(std::pair<size_t, Member*>(mem.m_id, &mem));
		mem.m_followedBy.insert(std::pair<size_t, Member*>(this->m_id, this));
		//can be done with move constructor make_pair;
		//std::make_pair()
	}
	else
	{
		//perror("You have already followed him");
		//cout << "You have already followed him"<<"\n";
	}
}
void Member::unfollow(Member& member)
{
	//if (m_follow.find(member.m_id) != m_follow.end());
	if(this->m_follow.count(member.m_id))
	{
		m_follow.erase(member.m_id);
		member.m_followedBy.erase(this->m_id);
	}
	else
	{
		//perror("You haven't followed him");
		//cout << "You haven't followed him" << "\n";
	}
}

int Member::numFollowers()
{
	return this->m_followedBy.size();
}

int Member::numFollowing()
{
	return this->m_follow.size();
}
int Member::count()
{
	return counter;
}