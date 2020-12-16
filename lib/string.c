// Copyright (c) 2020, Jiang Yinzuo. All rights reserved.

#include <corn_libc/string.h>

/**
 * strlen - calculate the length of the string @s, not including
 * the terminating '\0' character.
 * @s:      the input string
 *
 * The strlen() function returns the length of string @s.
 */
size_t strlen(const char *s)
{
	size_t cnt = 0;
	while (*s++ != '\0') {
		cnt++;
	}
	return cnt;
}

/**
 * strnlen - calculate the length of the string @s, not including
 * the terminating '\0' char acter, but at most @len.
 * @s:      the input string
 * @len:    the max-length that function will scan
 *
 * Note that, this function looks only at the first @len characters
 * at @s, and never beyond @s + @len.
 *
 * The return value is strlen(s), if that is less than @len, or
 * @len if there is no '\0' character among the first @len characters
 * pointed by @s.
 */
size_t strnlen(const char *s, size_t len)
{
	size_t cnt = 0;
	while (cnt < len && *s++ != '\0') {
		cnt++;
	}
	return cnt;
}