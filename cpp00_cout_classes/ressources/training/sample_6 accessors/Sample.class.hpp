#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

	int		a;
	int		b;
	int		c;

	Sample( int xa, int xb, int xc );
	~Sample( void );

	void	getBar( void ) const;
	void	setBar( int xa, int xb, int xc );
};

#endif
