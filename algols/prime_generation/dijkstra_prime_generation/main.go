package main

import (
	"crypto"
	"crypto/rand"
	"crypto/rsa"
	"crypto/sha256"
	//	"encoding/json"
	"fmt"
	"github.com/google/uuid"
	"github.com/notnil/chess"
	"github.com/notnil/chess/image"
	rn "math/rand"
	"os"
	"time"
)

type User struct {
	ID       string `json:"id"`
	Login    string `json:"login"`
	Password string `json:"password"`
}

type Game struct {
	GameID    string     `json:"gameid"`
	Player1id string     `json:"player1"`
	Player2id string     `json:"player2"`
	Time      time.Time  `json:"time"`
	Game      chess.Game `json:"game"`
	Moves     []string   `json:"moves"`
}

//
// func (g *Game) PossibleMoves() []string{
//
//
// }

func main() {
	player := User{}
	player.ID = uuid.NewString()
	player.Password = "farofa123"
	player.Login = "PudimDeCachaca"

	privateKey, err := rsa.GenerateKey(rand.Reader, 2048)
	if err != nil {
		panic(err)
	}
	publicKey := privateKey.PublicKey

	new_game := Game{}
	new_game.Game = *chess.NewGame()
	new_game.Moves = make([]string, 0)

	for new_game.Game.Outcome() == chess.NoOutcome {
		// select a random move
		moves := new_game.Game.ValidMoves()
		move := moves[rn.Intn(len(moves))]
		new_game.Moves = append(new_game.Moves, move.String())
		new_game.Game.Move(move)
	}
	a := []byte(player.Password)
	encryptedBytes, err := rsa.EncryptOAEP(
		sha256.New(),
		rand.Reader,
		&publicKey,
		a,
		nil)
	if err != nil {
		panic(err)
	}
	fmt.Println("encrypted bytes: ", string(encryptedBytes))
	info, err := privateKey.Decrypt(nil, encryptedBytes, &rsa.OAEPOptions{Hash: crypto.SHA256})
	if err != nil {
		panic(err)
	}
	fmt.Println(string(info))

	for i := range new_game.Moves {
		fmt.Println(new_game.Moves[i])
	}
	fmt.Println(len(new_game.Moves))

	file, _ := os.Create("output.svg")
	defer file.Close()
	image.SVG(file, new_game.Game.Position().Board())

}
