/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CPUModule.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thoraffr <thoraffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 19:07:59 by thoraffr          #+#    #+#             */
/*   Updated: 2015/06/28 22:41:37 by ksicart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CPUModule.hpp"


CPUModule::CPUModule()
{
	_gNbCores = _getNbCores();
//	mvprintw(6, 3, _gNbCores);
	refresh();
	_gMaxFreq = _getMaxFreq();
	mvprintw(7, 9, _gMaxFreq);
	refresh();
	_gBrandName = _getBrandName();
	_gProgBar = _getCpuFrequency(1);
	return ;
}

host_cpu_load_info	CPUModule::_getInstantCpuLoad()
{
	kern_return_t			error;
	mach_msg_type_number_t	count;
	host_cpu_load_info		r_load;
	mach_port_t				mach_port;

	count = HOST_CPU_LOAD_INFO_COUNT;
	mach_port = mach_host_self();
	error = host_statistics(mach_port, HOST_CPU_LOAD_INFO, (host_info_t)&r_load, &count);
	if (error != KERN_SUCCESS)
		return host_cpu_load_info();
	return r_load;
}

/*
class CpuUsage
{
 public:
  CpuUsage(unsigned int core): core_(core)
  {
  	prev = updated_ticks_(core);
  }
 
  float get() {
    Ticks t = updated_ticks_(core_);
    unsigned long long int used = t.used() - prev.used();
    unsigned long long int total = t.total() - prev.total();
    prev = t;
    return (float)used / (float)total * 100.0f;
  }
 
 private:
  struct Ticks
  {
    unsigned long long int usertime;
    unsigned long long int nicetime;
    unsigned long long int systemtime;
    unsigned long long int idletime;
 
    unsigned long long int used() { return usertime + nicetime + systemtime; }
    unsigned long long int total() { return usertime + nicetime + systemtime + idletime; }
  } prev;
 
  unsigned int core_;
 
  Ticks updated_ticks_(unsigned int core)
  {
    unsigned int cpu_count;
    processor_cpu_load_info_t cpu_load;
    mach_msg_type_number_t cpu_msg_count;
 
    int rc =  host_processor_info(
      mach_host_self( ),
      PROCESSOR_CPU_LOAD_INFO,
      &cpu_count,
      (processor_info_array_t *) &cpu_load,
      &cpu_msg_count
    );
    if (rc != 0) {
      printf("Error: failed to scan processor info (rc=%d)\n", rc);
      exit(1);
    }
 
    if (core < 0 || cpu_count <= 0) {
      printf("Error: invalid core number: %d\n", core);
      exit(1);
    }
    unsigned long long int usertime = cpu_load[core].cpu_ticks[CPU_STATE_USER];
    unsigned long long int nicetime = cpu_load[core].cpu_ticks[CPU_STATE_NICE];
    unsigned long long int systemtime = cpu_load[core].cpu_ticks[CPU_STATE_SYSTEM];
    unsigned long long int idletime = cpu_load[core].cpu_ticks[CPU_STATE_IDLE];
 
    Ticks t = {usertime, nicetime, systemtime, idletime};
    return t;
  }
 
};
*/

float				CPUModule::_getCpuFrequency(unsigned int core)
{
    unsigned int cpu_count;
    processor_cpu_load_info_t firstLoad;
    processor_cpu_load_info_t secondLoad;
    mach_msg_type_number_t cpu_msg_count;
    int rc;
 
    rc =  host_processor_info(
      mach_host_self( ),
      PROCESSOR_CPU_LOAD_INFO,
      &cpu_count,
      (processor_info_array_t *) &firstLoad,
      &cpu_msg_count
    );

    usleep(100000);
    rc =  host_processor_info(
      mach_host_self( ),
      PROCESSOR_CPU_LOAD_INFO,
      &cpu_count,
      (processor_info_array_t *) &secondLoad,
      &cpu_msg_count
    );

	unsigned long long int		diffTickUser = secondLoad[core].cpu_ticks[CPU_STATE_USER] - firstLoad[core].cpu_ticks[CPU_STATE_USER];
	unsigned long long int		diffTickSys = secondLoad[core].cpu_ticks[CPU_STATE_SYSTEM] - firstLoad[core].cpu_ticks[CPU_STATE_SYSTEM];
	unsigned long long int		diffTickNice = secondLoad[core].cpu_ticks[CPU_STATE_NICE] - firstLoad[core].cpu_ticks[CPU_STATE_NICE];
	unsigned long long int		diffTickIdle = secondLoad[core].cpu_ticks[CPU_STATE_IDLE] - firstLoad[core].cpu_ticks[CPU_STATE_IDLE];

	return static_cast<float>(diffTickUser + diffTickSys + diffTickNice) / static_cast<float>(diffTickUser + diffTickSys + diffTickNice + diffTickIdle) * 100.0;
}

int				CPUModule::_getNbCores()
{
	int numCPU = sysconf( _SC_NPROCESSORS_ONLN );
return numCPU;
}

char*				CPUModule::_getMaxFreq()
{
	size_t	bufsize;
	char*	buf;

	sysctlbyname("hw.cpufrequency", NULL, &bufsize, NULL, 0);
	buf = new char[bufsize];
	sysctlbyname("hw.cpufrequency", buf, &bufsize, NULL, 0);

	return buf;
}

char*				CPUModule::_getBrandName()
{
	size_t	bufsize;
	char*	buf;

	sysctlbyname("machdep.cpu.brand_string.", NULL, &bufsize, NULL, 0);
	buf = new char[bufsize];
	sysctlbyname("machdep.cpu.brand_string", buf, &bufsize, NULL, 0);

	return buf;
}

void				CPUModule::update( void )
{
	return ;
}

void				CPUModule::update(sf::RenderWindow & window)
{
	int		i = 0;
	sf::Text	brand;
	sf::Text	cores;
	sf::Text	title;
	sf::Font	font;
	sf::Text	frt;
	sf::RectangleShape	rectangle(sf::Vector2f(600, 20));
	rectangle.setPosition(0, 100);

	font.loadFromFile("arial.ttf");

	title.setString("Processor Informations");
	title.setFont(font);
	title.setCharacterSize(15);
	title.setColor(sf::Color::Black);
	title.setPosition(25, 102);

	brand.setString(this->_getBrandName());
	brand.setFont(font);
	brand.setCharacterSize(12);
	brand.setColor(sf::Color::White);
	brand.setPosition(25, 135);

	std::string	buf;
	buf = "Number of cores: " + std::to_string(this->_getNbCores());
	cores.setString(buf);
	cores.setFont(font);
	cores.setCharacterSize(12);
	cores.setColor(sf::Color::White);
	cores.setPosition(25, 155);

	window.draw(rectangle);
	window.draw(title);
	window.draw(brand);
	window.draw(cores);

	frt.setString("Core frequencies:");
	frt.setFont(font);
	frt.setCharacterSize(12);
	frt.setColor(sf::Color::White);
	frt.setPosition(25, 175);
	window.draw(frt);
	
	sf::Text	freq;
	while (i < this->_getNbCores())
	{
		buf = "CPU #" + std::to_string(i) + ": " + std::to_string(this->_getCpuFrequency(i));
		freq.setString(buf);
		freq.setFont(font);
		freq.setCharacterSize(12);
		freq.setColor(sf::Color::White);
		++i;
		freq.setPosition(25, 175 + (i * 20));
		window.draw(freq);
	}

	return ;
}
void				CPUModule::displayTerm()
{
	int	i;

	i = 0;
	mvprintw(6, 5, "Processor Informations:");
	mvprintw(7, 7, "CPU : %s\n", this->_getBrandName());
	mvprintw(8, 7, "CPU nb cores: %d\n", this->_getNbCores());
	while (i < this->_getNbCores())
	{
		mvprintw(9 + i, 7, "Core[%d] usage : %f\n", i + 1, this->_getCpuFrequency(i));
		++i;
	}
	return ;
}

CPUModule::~CPUModule()
{
	return ;
}
