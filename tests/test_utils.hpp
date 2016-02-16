#ifndef _TEST_UTILS_H_
#define _TEST_UTILS_H_


template <int value = 42>
struct set_to_float {

  float operator()(){

    return float(value);
    
  }
  
};

template<typename in_type, typename out_type = in_type>
struct diff_squared {

  out_type operator()(const in_type& _first, const in_type& _second){

    out_type value = _first - _second;
    return (value*value);
    
  }
  
};



struct ramp
{
  size_t value;

  ramp():
    value(0){};
  
  float operator()(){

    return value++;
    
  }
  
};
  

template <typename value_policy = ramp>
struct stack_fixture {

  fc::image_stack stack;
  fc::image_stack kernel;

  template <typename T>
  stack_fixture(const std::vector<T>& _stack_shape,
	       const std::vector<T>& _kernel_shape):
    stack(_stack_shape),
    kernel(_kernel_shape){

    value_policy operation;
    std::fill(kernel.data(),kernel.data()+kernel.num_elements(),0);
    std::generate(stack.data(),stack.data()+stack.num_elements(),operation);
    
  }
  
};


#endif /* _TEST_UTILS_H_ */
