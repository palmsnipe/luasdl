setWindowTitle("Projet LuaSDL :D")
setWindowSize(600, 400)

event = require("event")

function	program()

   addFont("fonts/Ubuntu-M.ttf", "ubuntu", 40)

   while run() == 1 do
      point(20, 20, 0, 255, 0)
      line(40, 40, 300, 60, 255, 255, 0)
      circle(40, 60, 50, 255,255,255)
      circle(480, 60, 50, 255, 0,255)
      waitevent()
   end
end

program()