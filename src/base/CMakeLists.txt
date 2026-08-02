file(GLOB SRC *.cc *.hh)

target_sources(fstdcxx PRIVATE ${SRC})
target_sources(fstdcxx_hosted PRIVATE ${SRC})
