#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<std::string> strarray_t;

static strarray_t& split(const char *str, const char *delim, strarray_t &ret);

int
main(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
	strarray_t array;
	split(av[i], " \t\r\n", array);
	printf("token : \"%s\"\n", av[i]);
	int num = 0;
	strarray_t::iterator it = array.begin();
	while (it != array.end()) {
	    printf("  %d:\"\x1b[34m%s\x1b[39m\"\n", num + 1, (*it).c_str());
	    it++;
	    num++;
	}
    }

    return 0;
}

/**
 * Split string by specified delimiter.
 *
 * @param str String.
 * @param delim Delimiter.
 * @param ret Array to store tokens.
 * @return Passed ret returned.
 */
static strarray_t&
split(const char *str, const char *delim, strarray_t &ret)
{
    std::string tmp(str);

    std::string::size_type search_begin = 0;

    while (true) {
	std::string::size_type begin
		= tmp.find_first_not_of(delim, search_begin);
	if (begin == std::string::npos) {
	    break;
	}
	if (tmp.at(begin) == '\"') {
	    std::string::size_type end = tmp.find_first_of('\"', begin + 1);
	    if (end == std::string::npos) {
		end = tmp.find_first_of(delim, begin);
		ret.push_back(tmp.substr(begin, end - begin));
		search_begin = end;
	    } else {
		end++;
		ret.push_back(tmp.substr(begin + 1, end - begin - 2));
		search_begin = end;
	    }
	} else {
	    std::string::size_type end = tmp.find_first_of(delim, begin);
	    ret.push_back(tmp.substr(begin, end - begin));
	    search_begin = end;
	}
    }

    return ret;
}
