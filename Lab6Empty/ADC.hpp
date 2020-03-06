enum class Resolution
{
  Bits12,
  Bits10,
  Bits8,
  Bits6
};


template<class T>


class ADC
{
public:
  
  static void Start()
  {
   T::CR2::SWSTART::On::Set(); //Start conversion
  }
    
  static void On()
  {
   T::CR2::ADON::Enable::Set(); // Enable ADC1
  }
    
  static void Off()
  {
   T::CR2::ADON::Disable::Set();
  }
    
  static bool IsReady()
  {
   return T::SR::EOC::ConversionComplete::IsSet();
  }
    
  static std::uint32_t Get()
  {
    return T::DR::Get();
  }
  static void Config(Resolution resolution)
  {
    switch(resolution)
    {
    case Resolution::Bits12:
      T::CR1::RES::Bits12::Set();
      break;
      
      case Resolution::Bits10:
      T::CR1::RES::Bits10::Set();
      break;
      
      case Resolution::Bits8:
      T::CR1::RES::Bits8::Set();
      break;
      
      case Resolution::Bits6:
      T::CR1::RES::Bits6::Set();
      break;
      
      default:
      T::CR1::RES::Bits12::Set();
      break;
    }
  }
  static void SetChannels (std::uint32_t channelNum1, std::uint32_t channelNum2)
   
    {
      T::SQR1::L::Conversions2::Set();
      T::CR1::SCAN::Enable::Set();
      T::CR2::EOCS::SingleConversion::Set();
      T::CR2::CONT::SingleConversion::Set();
      assert(channelNum1 <19);
      assert(channelNum2 <19);
      T::SQR3::SQ1::Set(channelNum1);
      T::SQR3::SQ2::Set(channelNum2);
    }  
};



