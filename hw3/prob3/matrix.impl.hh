
template <class T>
matrix<T>::matrix ( int r, int c ) : num_rows(r), num_columns(c) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to initialize a matrix with non-positive number of rows and/or columns");
  }

  value = new T[r*c];

  for ( int i=0; i<r*c; i++ ) {
    value[i] = (T) 0;
  }

}

template <class T>
matrix<T>::~matrix() {
  delete []value;
}

template <class T>
matrix<T>::matrix( const matrix &m ) {

    num_rows = m.num_rows;
    num_columns = m.num_columns;
    value = new T [num_rows*num_columns];

    for ( int i=0; i<rows(); i++ ) {
      for ( int j=0; j<columns(); j++ ) {
        set(i,j,m.get(i,j));
      }
    }

}

template <class T>
matrix<T> &matrix<T>::operator=(const matrix &other) {

  if ( this != &other ) {
    num_rows = other.num_rows;
    num_columns = other.num_columns;
    T * temp = new T [num_rows*num_columns];
    for ( int i=0; i<num_rows*num_columns; i++ ) {
      temp[i] = (T) other.value[i];
    }
    delete []value;
    value = temp;
  }

  return *this;

}

template <class T>
T matrix<T>::get(int r, int c) const {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::get");
  }

  return value[r * columns() + c];

}

template <class T>
void matrix<T>::set(int r, int c, T x) {
  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::set");
  }
  value[r * columns() + c] = x;
}

template <class T>
matrix<T> matrix<T>::identity ( int s ) {

  matrix m(s);

  for ( int i=0; i<s; i++ ) {
    m.set(i,i, (T) 1.0);
  }

  return m;

}

template <class T>
matrix<T> matrix<T>::ones ( int r, int c ) {

  matrix m(r,c);

  for ( int i=0; i<r; i++ ) {
    for ( int j=0; j<c; j++ ) {
      m.set(i,j, (T) 1.0);
    }
  }

  return m;

}
/*
template <class T>
matrix<T> matrix<T>::random( int r, int c, T min, T max ) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to build a random matrix with non-positive number of rows and/or columns");
  }

  if ( max <= min ) {
    throw matrix_exception("Min is not less than max when building a random matrix");
  }

  matrix m(r,c);
  T d = max - min + 1,
      h = d / 2;

  for ( int i=0; i<r; i++ ) {
    for ( int j=0; j<c; j++ ) {
      m.set(i,j, (T)(rand()%d-h) );
    }
  }

  return m;

}*/

template <class T>
bool matrix<T>::in_range(int r, int c) const {
  return 0 <= r && r < rows() && 0 <= c && c < columns();
}


template <class T>
matrix<T> matrix<T>::add ( const matrix &m ) const {

  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to add matrices with incompatible sizes");
  }

  matrix M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      M.set(i,j,(T) (get(i,j) + m.get(i,j))); /* NOTE: Casting result back to T */
    }
  }

  return M;

}

template <class T>
matrix<T> matrix<T>::mult ( const matrix &m ) const {

  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to mult matrices with incompatible sizes");
  }

  matrix M(rows(),m.columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      M.set(i,j,(T) 0);
      for ( int k=0; k<columns(); k++ ) {
        M.set(i,j, (T) (M.get(i,j) + get(i,k) * m.get(k,j) ) );
      }
    }
  }

  return M;

}

template <class T>
void matrix<T>::scale ( double d ) {
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      set(i,j,(T) (get(i,j) * d) );
    }
  }
}

template <class T>
bool matrix<T>::equals ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( get(i,j) != m.get(i,j) ) {
        return false;
      }
    }
  }
  return true;
}

template <class T>
bool matrix<T>::less_than ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( get(i,j) >= m.get(i,j) ) {
        return false;
      }
    }
  }
  return true;
}

template <class T>
matrix<T> matrix<T>::m_minor ( int r, int c ) {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Attempted to take m_minor with out of range indices");
  }

  matrix p ( rows() - 1, columns() - 1 );

  int I, J;

  for ( int i=0, I=0; i<rows(); i++ ) {
    for ( int j=0, J=0; j<columns(); j++ ) {
      if ( i != r && j != c ) {
        p.set(I,J, (T) get(i,j));
        J++;
      }
    }
    if ( i != r ) {
      I++;
    }
  }

  return p;

}

template <class T>
T matrix<T>::det(void) {

  if ( rows() == 1 && columns() == 1 ) {

    return get(0,0);

  } else {

    T sign = 1, sum = 0;
    for ( int i=0; i<columns(); i++ ) {
      sum  = sum +  ( sign * get(0,i) * m_minor(0,i).det() );
      sign = sign * -1;
    }

    return sum;

  }

}

template <class T>
matrix<T> matrix<T>::inverse ( void ) {

  matrix m(rows(),columns());

  if ( rows() != columns() ) {
    throw matrix_exception("Attempted to invert non-square matrix");
  }

  T d = det();

  if ( d == 0 ) {
    throw matrix_exception("Attempted to invert non-invertible matrix");
  }

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      T sign = ( (i+j)%2 == 0 ) ? 1 : -1;
      m.set(i,j, (T)(sign* (m_minor(j,i).det() /d) ) );
    }
  }

  return m;

}

template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T> &m) {

  for ( int i=0; i<m.rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      os << m.get(i,j) << '\t';
    }
    os << std::endl;
  }

  return os;

}
