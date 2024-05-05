#include <stdlib.h>
#include <limits.h>

unsigned int	ft_abs(int n)
{
	if (n > 0)
		return ((unsigned int)n);
	else
		return (-(unsigned int) n);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			n_len;
	unsigned int	n_cpy;
	int				is_neg;

	is_neg = n < 0;
	n_len = 0;
	n_cpy = ft_abs(n) + !n;
	while (n_cpy * ++n_len != 0)
		n_cpy /= 10;
	--n_len;
	str = malloc(sizeof(*str) * (n_len + (size_t)is_neg + 1));
	if (!str)
		return (NULL);
	str += (int)n_len + is_neg;
	n_cpy = ft_abs(n);
	*str-- = 0;
	while (n_len--)
	{
		*str-- = (char)(n_cpy % 10 + '0');
		n_cpy /= 10;
	}
	if (is_neg)
		*str-- = '-';
	return (++str);
}

/* count utf-8 code points in byte stream */
size_t	ft_utf_8_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
		count += (*s++ & 0xc0) != 0x80;
	return (count);
}

size_t	ft_strlen(char const *s)
{
	size_t	length;

	length = 0;
	while (*s++)
		length++;
	return (length);
}

int	ft_char_in_charset(char c, char const *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

static size_t	len_after_trim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	start;
	size_t	end;

	idx = 0;
	while (ft_char_in_charset(s1[idx], set))
		++idx;
	if (!s1[idx])
		return (0);
	start = idx;
	while (s1[idx])
		++idx;
	--idx;
	while (ft_char_in_charset(s1[idx], set))
		--idx;
	end = idx;
	return (end - start + 1);
}

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	len;

	len = 0;
	while (len + 1 < size && src[len])
		*dst++ = src[len++];
	if (size)
		*dst = 0;
	while (src[len])
		len++;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_len;
	char	*trimmed_str;

	trimmed_len = len_after_trim(s1, set);
	trimmed_str = malloc(sizeof(*trimmed_str) * (trimmed_len + 1));
	if (!trimmed_str)
		return (NULL);
	while (ft_char_in_charset(*s1, set))
		++s1;
	ft_strlcpy(trimmed_str, s1, trimmed_len + 1);
	return (trimmed_str);
}

char	*ft_strrchr(char const *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
		if (*s++ == (char) c)
			last = (char *)(s - 1);
	if (*s == (char) c)
		return ((char *) s);
	return (last);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (*us1 && *us2 && *us1 == *us2)
	{
		++us1;
		++us2;
	}
	return (*us1 - *us2);
}

int	ft_strncmp(char const *s1, char const *s2, size_t len)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (!len)
		return (0);
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while (*us1 && *us2 && *us1 == *us2 && --len)
	{
		us1++;
		us2++;
	}
	if (*us1 != *us2)
		return ((*us1 - *us2 != 0)
			* (-2 * (*us1 - *us2 < 0) + 1));
	return (0);
}

size_t	ft_count_all(
	const char str[static 1],
	const char pattern[static 1])
{
	size_t	pattern_len;
	size_t	pattern_count;

	pattern_len = ft_strlen(pattern);
	pattern_count = 0;
	while (*str)
	{
		if (!ft_strncmp(str, pattern, pattern_len))
		{
			pattern_count += 1;
			str += pattern_len;
			if (!pattern_len)
				++str;
		}
		else
			++str;
	}
	if (!pattern_len)
		pattern_count += 1;
	return (pattern_count);
}

char	*ft_replace_all(
	const char str[static 1],
	const char pattern[static 1],
	const char replacement[static 1])
{
	size_t	pattern_len;
	size_t	replacement_len;
	size_t	str_idx;
	size_t	new_str_idx;
	char	*new_str;

	pattern_len = ft_strlen(pattern);
	replacement_len = ft_strlen(replacement);
	new_str = malloc(sizeof(*new_str) * (1 + ft_strlen(str)
				+ (replacement_len - pattern_len) * ft_count_all(str, pattern)));
	str_idx = 0;
	new_str_idx = 0;
	while (str[str_idx])
	{
		if (!ft_strncmp(str + str_idx, pattern, pattern_len))
		{
			ft_strlcpy(new_str + new_str_idx, replacement, replacement_len + 1);
			str_idx += pattern_len;
			new_str_idx += replacement_len;
			if (!pattern_len)
				new_str[new_str_idx++] = str[str_idx++];
		}
		else
			new_str[new_str_idx++] = str[str_idx++];
	}
	if (!pattern_len)
	{
		ft_strlcpy(new_str + new_str_idx, replacement, replacement_len + 1);
		new_str_idx += replacement_len;
	}
	new_str[new_str_idx] = 0;
	return (new_str);
}

static size_t	split_arr_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	if (*s == 0)
		return (1);
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			return (len);
		++len;
		while (*s != c && *s)
			++s;
	}
	return (len);
}

static int	save_strlcpy(char **arr, size_t len, char const *src, size_t size)
{
	if (!arr[len - 1])
		return (0);
	ft_strlcpy(arr[len - 1], src, size);
	return (1);
}

char	*ft_strdup(char const *s)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s);
	s2 = malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, (char *) s, len + 1);
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	size_t		arr_len;
	size_t		idx;
	char		**arr;
	char const	*start;

	arr_len = split_arr_len(s, c);
	arr = malloc(sizeof(*arr) * (arr_len + 1));
	idx = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (!*s)
			break ;
		start = s;
		while (*s != c && *s)
			++s;
		arr[idx] = malloc(sizeof(**arr) * (size_t)(s - start + 1));
		if (!save_strlcpy(arr, ++idx, start, (size_t)(s - start + 1)))
			return (NULL);
	}
	if (idx == 0)
		arr[idx++] = ft_strdup("");
	arr[idx] = NULL;
	return (arr);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_bzero(void *ptr, size_t n)
{
	char	*p;

	p = (char *)ptr;
	while (n--)
		*p++ = (unsigned char) 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	void	*empty;

	if (nmemb * size == 0)
	{
		empty = malloc(0);
		if (!empty)
			return (NULL);
		return (empty);
	}
	if (UINT_MAX / nmemb < size)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	idx;
	size_t	sidx;
	size_t	slen;
	size_t	dlen;

	slen = 0;
	while (src[slen])
		++slen;
	idx = 0;
	while (dst[idx] && idx < size)
		++idx;
	dlen = idx;
	if (dlen == size)
		return (slen + size);
	sidx = 0;
	size -= dlen;
	while (size-- > 1 && src[sidx])
		dst[idx++] = src[sidx++];
	dst[idx] = 0;
	return (dlen + slen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*joined_str;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = ft_calloc(total_len + 1, sizeof(*joined_str));
	if (!joined_str)
		return (NULL);
	ft_strlcat(joined_str, s1, total_len + 1);
	ft_strlcat(joined_str, s2, total_len + 1);
	return (joined_str);
}
