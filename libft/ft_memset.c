/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboudrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:34:58 by cboudrin          #+#    #+#             */
/*   Updated: 2021/11/23 10:53:24 by cboudrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memset (void *p, int v, unsigned int s)
{
	unsigned char *i = p;
	while (s--)
	{
		*i++ == (unsigned char)v;
	}
	return (p);
}

int main() {

    int array [] = { 54, 85, 20, 63, 21 };
    unsigned int size = sizeof( int ) * 5;
    int length;

    /* Display the initial values */
    for( length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    /* Reset the memory bloc */
    ft_memset(array, 0, size );

    /* Display the new values */
    for( length=0; length<5; length++) {
        printf( "%d ", array[ length ] );
    }
    printf( "\n" );

    return 0;
}
