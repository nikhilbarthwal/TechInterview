module Program

let pages : Page.Page list = [ ]

[<EntryPoint>]
let main argv =

    let config = new Base.Config(argv.[0])

    // TODO: Generate index.html

    pages |> List.iter (fun x -> x.render pages config)

    0 // return an integer exit code
