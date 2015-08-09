#include <iostream>
#include <sys/utsname.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/sysctl.h>
#include <sys/wait.h>
#include <mach/vm_statistics.h>
#include <mach/vm_map.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
#include <mach/mach_error.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>

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
 
  //  if (core < 0 || cpu_count <= core) {
    //  printf("Error: invalid core number: %d\n", core);
     // exit(1);
   // }
    unsigned long long int usertime = cpu_load[core].cpu_ticks[CPU_STATE_USER];
    unsigned long long int nicetime = cpu_load[core].cpu_ticks[CPU_STATE_NICE];
    unsigned long long int systemtime = cpu_load[core].cpu_ticks[CPU_STATE_SYSTEM];
    unsigned long long int idletime = cpu_load[core].cpu_ticks[CPU_STATE_IDLE];
 
    Ticks t = {usertime, nicetime, systemtime, idletime};
    return t;
  }
 
};

int main()
{
	struct utsname uts;
	uname(&uts);
	std::cout  << "uts.sysname " << uts.sysname << std::endl;
	std::cout  << "uts.nodename " << uts.nodename << std::endl;
	std::cout  << "uts.release " << uts.release << std::endl;
	std::cout  << "uts.machine " << uts.machine << std::endl;

	#ifdef _WIN32
	std::cout << "Windows 32-bit" << std::endl;
	#elif _WIN64
	std::cout << "Windows 64-bit" << std::endl;
	#elif __unix || __unix__
	std::cout << "Unix" << std::endl;
	#elif __APPLE__ || __MACH__
	std::cout << "Mac OS X" << std::endl;
	#elif __linux__
	std::cout << "Linux" << std::endl;
	#elif __FreeBSD__
	std::cout << "FreeBSD" << std::endl;
	#else
	std::cout << "Other" << std::endl;
	#endif

	register struct passwd *pw;
	register uid_t uid;

	uid = geteuid();
	pw = getpwuid(uid);
	if (pw)
		std::cout << std::string(pw->pw_name) << std::endl;
	else
		std::cout << std::string("") << std::endl;

	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];

	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", &tstruct);
	std::cout << buf << std::endl;

	int pid = fork();
	if (pid == 0)
		execl("/usr/sbin/sysctl", "/usr/sbin/sysctl", "-n", "hw.memsize", static_cast<char *>(0));
	wait(0);

	pid = fork();
	if (pid == 0)
		execl("/usr/sbin/sysctl", "/usr/sbin/sysctl", "hw.physicalcpu", static_cast<char *>(0));
	wait(0);

	pid = fork();
	if (pid == 0)
		execl("/usr/sbin/sysctl", "/usr/sbin/sysctl", "-n", "vm.swapusage", static_cast<char *>(0));
	wait(0);

	pid = fork();
	if (pid == 0)
		execl("/usr/sbin/sysctl", "/usr/sbin/sysctl", "hw.cpufrequency", static_cast<char *>(0));
	wait(0);

	pid = fork();
	if (pid == 0)
		execl("/usr/sbin/sysctl", "/usr/sbin/sysctl", "machdep.cpu.brand_string", static_cast<char *>(0));
	wait(0);

	{
		vm_size_t page_size;
		mach_port_t mach_port;
		mach_msg_type_number_t count;
		vm_statistics64_data_t vm_stats;

		mach_port = mach_host_self();
		count = sizeof(vm_stats) / sizeof(natural_t);
		if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
				KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
					(host_info64_t)&vm_stats, &count))
		{
			long double free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;
			long double used_memory = ((int64_t)vm_stats.active_count +
					(int64_t)vm_stats.inactive_count +
					(int64_t)vm_stats.wire_count) *  (int64_t)page_size;
			printf("page_size: %lld\n", (int64_t)page_size);
			printf("free memory: %Lf\nused memory: %Lf\n", free_memory / (1000000), used_memory / (1000000));
		}
	}


	{
		static unsigned long long _previousTotalTicks = 0;
		static unsigned long long _previousIdleTicks = 0;

		host_cpu_load_info_data_t cpuinfo;
		mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;
		if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, (host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
		{
			unsigned long long totalTicks = 0;
			for(int i=0; i < CPU_STATE_MAX; i++)
				totalTicks += cpuinfo.cpu_ticks[i];
			unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
			unsigned long long idleTicksSinceLastTime  = cpuinfo.cpu_ticks[CPU_STATE_SYSTEM] - _previousIdleTicks;
			float sysLoadPercentage = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);
			sleep(1);
			_previousTotalTicks = totalTicks;
			_previousIdleTicks  = cpuinfo.cpu_ticks[CPU_STATE_SYSTEM];
			std::cout <<  sysLoadPercentage << std::endl;
		}
		else
			std::cout << -1.0f << std::endl;
	}

{
		caddr_t ref, buf, end;
		size_t bufsiz;
		struct if_msghdr *ifm;
		long double totalibytes = 0;
		long double totalobytes = 0;
		long double totalipckts = 0;
		long double totalopckts = 0;
		long double difftotalibytes = 0;
		long double difftotalobytes = 0;
		long double difftotalipckts = 0;
		long double difftotalopckts = 0;

		int mib[6] =
		{
			CTL_NET,
			PF_ROUTE,
			0,
			0,
			NET_RT_IFLIST,
			0
		};

		if (sysctl (mib, 6, NULL, &bufsiz, NULL, 0) < 0) 
		std::cout << "ECHEC" << std::endl;

		buf = ref = (caddr_t)malloc(bufsiz);

		if (sysctl (mib, 6, buf, &bufsiz, NULL, 0) < 0)
			std::cout << "ECHEC" << std::endl;

		for (end = buf + bufsiz; buf < end; buf += ifm->ifm_msglen) 
		{

			ifm = (struct if_msghdr *) buf;
			if (ifm->ifm_type == RTM_IFINFO)
			{
				totalibytes += ifm->ifm_data.ifi_ibytes;
				totalobytes += ifm->ifm_data.ifi_obytes;
				totalipckts += ifm->ifm_data.ifi_ipackets;
				totalopckts += ifm->ifm_data.ifi_opackets;
			}
		}
		std::cout << totalibytes << " " << totalobytes << std::endl;
		std::cout << totalipckts << " " << totalopckts << std::endl;
		sleep(1);
		//if (sysctl (mib, 6, NULL, &bufsiz, NULL, 0) < 0) 
		//	std::cout << "ECHEC" << std::endl;

		//buf = ref = (caddr_t)malloc(bufsiz);
		if (sysctl (mib, 6, buf, &bufsiz, NULL, 0) < 0)
			std::cout << "ECHEC" << std::endl;

		for (end = buf + bufsiz; buf < end; buf += ifm->ifm_msglen) 
		{

			ifm = (struct if_msghdr *) buf;
			if (ifm->ifm_type == RTM_IFINFO)
			{
				difftotalibytes += ifm->ifm_data.ifi_ibytes;
				difftotalobytes += ifm->ifm_data.ifi_obytes;
				difftotalipckts += ifm->ifm_data.ifi_ipackets;
				difftotalopckts += ifm->ifm_data.ifi_opackets;
			}
		}
		std::cout << (difftotalibytes - totalibytes) / 1024 << " " << (difftotalobytes - totalobytes) / 1024 << std::endl;
		std::cout << (difftotalipckts - totalipckts) << " " << (difftotalopckts - totalopckts) << std::endl;
		printf("%Lf", (difftotalibytes - totalibytes) / 1024);
}
//CpuUsage a(0), b(1), c(2), d(3), e(4);
 // usleep(100000);
 // printf("%6.2f, %6.2f, %6.2f, %6.2f\n", a.get(), b.get(), c.get(), e.get());
 // usleep(100000);
 // printf("%6.2f, %6.2f, %6.2f, %6.2f\n", a.get(), b.get(), c.get(), d.get());
 // usleep(100000);
  //printf("%6.2f, %6.2f, %6.2f, %6.2f\n", a.get(), b.get(), c.get(), d.get());
	return 0;
}
