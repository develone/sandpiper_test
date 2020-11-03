//iverilog -o hello hello.v
//vvp hello
module hello;
  initial 
    begin
      $display("Hello, World");
      $finish ;
    end
endmodule
