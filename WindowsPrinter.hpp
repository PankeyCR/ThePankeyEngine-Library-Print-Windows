#pragma once

#include <iostream>
#include "Byte.hpp"
#include "MemorySize.hpp"
#include "Print_CharPointer.hpp"

namespace pankey{

	namespace Library{

		namespace Print{

			struct WindowsPrinter{
				pankey::Memory::Allocator::memory_size write(pankey::Type::Array::Byte byte){
					std::cout << static_cast<char>(byte);
					return 1;
				}
				
				pankey::Memory::Allocator::memory_size writeInt(int a_data){
					std::cout << a_data;
					return 1;
				}

				pankey::Memory::Allocator::memory_size writeString(const char* str){
					if(str == nullptr){
						return 0;
					}
					std::cout << str;
					return std::char_traits<char>::length(str);
				}

				pankey::Memory::Allocator::memory_size newline(){
					std::cout << std::endl;
					return 1;
				}

				void flush(){
					std::cout << std::flush;
				}
			};

			WindowsPrinter g_printer;

			template<class T>
			void print(const T& a_value){
				pankey::Support::Print::template print<WindowsPrinter>(g_printer, a_value);
			}

			template<class T>
			void println(const T& a_value){
				pankey::Support::Print::template print<WindowsPrinter>(g_printer, a_value);
				g_printer.newline();
			}

			void println(){
				g_printer.newline();
			}

		}

	}

}